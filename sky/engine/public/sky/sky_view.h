// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_ENGINE_PUBLIC_SKY_SKY_VIEW_H_
#define SKY_ENGINE_PUBLIC_SKY_SKY_VIEW_H_

#include <memory>

#include "flutter/flow/layers/layer_tree.h"
#include "lib/ftl/macros.h"
#include "mojo/public/cpp/system/data_pipe.h"
#include "mojo/services/network/interfaces/url_loader.mojom.h"
#include "flutter/sky/engine/bindings/flutter_dart_state.h"
#include "flutter/sky/engine/core/window/window.h"
#include "flutter/sky/engine/public/platform/WebCommon.h"
#include "flutter/sky/engine/wtf/OwnPtr.h"
#include "flutter/sky/engine/wtf/RefPtr.h"
#include "flutter/sky/engine/wtf/text/WTFString.h"
#include "flutter/services/engine/sky_engine.mojom.h"
#include "flutter/services/pointer/pointer.mojom.h"
#include "third_party/skia/include/core/SkPicture.h"

namespace blink {
class DartController;
class DartLibraryProvider;
class Scene;
class SkyViewClient;
class View;
class Window;

class SkyView : public WindowClient, public IsolateClient {
 public:
  static std::unique_ptr<SkyView> Create(SkyViewClient* client);
  ~SkyView();

  void SetViewportMetrics(const sky::ViewportMetricsPtr& metrics);
  void SetLocale(const std::string& language_code,
                 const std::string& country_code);
  void PushRoute(const std::string& route);
  void PopRoute();

  void BeginFrame(ftl::TimePoint frame_time);

  void CreateView(const std::string& script_uri);
  DartController* dart_controller() const { return dart_controller_.get(); }

  void HandlePointerPacket(const pointer::PointerPacketPtr& packet);

  void OnAppLifecycleStateChanged(sky::AppLifecycleState state);

  Dart_Port GetMainPort();

 private:
  explicit SkyView(SkyViewClient* client);

  Window* GetWindow();

  void ScheduleFrame() override;
  void FlushRealTimeEvents() override;
  void Render(Scene* scene) override;

  void DidCreateSecondaryIsolate(Dart_Isolate isolate) override;

  SkyViewClient* client_;
  sky::ViewportMetricsPtr viewport_metrics_;
  std::string language_code_;
  std::string country_code_;
  std::unique_ptr<DartController> dart_controller_;

  FTL_DISALLOW_COPY_AND_ASSIGN(SkyView);
};

}  // namespace blink

#endif  // SKY_ENGINE_PUBLIC_SKY_SKY_VIEW_H_
