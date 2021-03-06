// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKY_ENGINE_CORE_DIAGNOSTIC_DIAGNOSTIC_SERVER_H_
#define SKY_ENGINE_CORE_DIAGNOSTIC_DIAGNOSTIC_SERVER_H_

#include "dart/runtime/include/dart_api.h"

namespace sky {
namespace shell {

class DiagnosticServer {
 public:
  static void Start();
  static void HandleSkiaPictureRequest(Dart_Handle send_port);

 private:
  static void SkiaPictureTask(Dart_Port port_id);
};

}  // namespace shell
}  // namespace sky

#endif  // SKY_ENGINE_CORE_DIAGNOSTIC_DIAGNOSTIC_SERVER_H_
