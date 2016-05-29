/*
 * \copyright Copyright 2015 All Rights Reserved.
 * \license @{
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @}
 */

#include "quantsystem/common/packets/algorithm_status_packet.h"
namespace quantsystem {
namespace packets {
AlgorithmStatusPacket::AlgorithmStatusPacket()
    : Packet(kAlgorithmStatus) {
}

AlgorithmStatusPacket::AlgorithmStatusPacket(const string& in_algorithm_id,
                                               AlgorithmStatus::Enum in_status,
                                               const string& in_message)
    : Packet(kAlgorithmStatus),
      status(in_status),
      algorithm_id(in_algorithm_id),
      message(in_message) {
}

AlgorithmStatusPacket::~AlgorithmStatusPacket() {
}
}  // namespace packets
}  // namespace quantsystem
