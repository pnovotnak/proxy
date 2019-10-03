/* Copyright 2017 Istio Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ISTIO_CONTROL_THRIFT_REQUEST_HANDLER_H
#define ISTIO_CONTROL_THRIFT_REQUEST_HANDLER_H

#include "include/istio/control/thrift/check_data.h"
#include "include/istio/control/thrift/report_data.h"
#include "include/istio/mixerclient/client.h"

namespace istio {
namespace control {
namespace thrift {

// The interface to handle a THRIFT request.
class RequestHandler {
 public:
  virtual ~RequestHandler() {}

  // Perform a Check call. It will:
  // * extract downstream thrift connection attributes
  // * check config, make a Check call if necessary.
  virtual void Check(CheckData* check_data,
                     const ::istio::mixerclient::CheckDoneFunc& on_done) = 0;

  virtual void ResetCancel() = 0;

  virtual void CancelCheck() = 0;

  // Make report call.
  virtual void Report(ReportData* report_data,
                      ReportData::ConnectionEvent event) = 0;
};

}  // namespace thrift
}  // namespace control
}  // namespace istio

#endif  // ISTIO_CONTROL_THRIFT_REQUEST_HANDLER_H
