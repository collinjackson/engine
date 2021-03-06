// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_ENGINE_CORE_SCRIPT_UI_DART_STATE_H_
#define SKY_ENGINE_CORE_SCRIPT_UI_DART_STATE_H_

#include "flutter/sky/engine/bindings/flutter_dart_state.h"
#include "flutter/sky/engine/platform/fonts/FontSelector.h"
#include "flutter/sky/engine/wtf/RefPtr.h"

namespace blink {
class Window;

class UIDartState : public FlutterDartState {
 public:
  UIDartState(IsolateClient* isolate_client, const std::string& url,
              std::unique_ptr<Window> window);
  ~UIDartState() override;

  Window* window() const { return window_.get(); }

  static UIDartState* Current();

  void set_font_selector(PassRefPtr<FontSelector> selector);
  PassRefPtr<FontSelector> font_selector();

 private:
  std::unique_ptr<Window> window_;
  RefPtr<FontSelector> font_selector_;
};

}  // namespace blink

#endif // SKY_ENGINE_CORE_SCRIPT_UI_DART_STATE_H_
