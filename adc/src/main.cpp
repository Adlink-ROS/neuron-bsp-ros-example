// Copyright 2019 ADLINK Technology Ltd. Advanced Robotic Platform Group
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <vector>

#include <neuron/platform/types.hpp>
#include <neuron/adc/adc.hpp>

#include <ros/ros.h>
#include <ros/rosconsole.h>

using namespace neuron;

int main(int argc, char* argv[])
{
  nbsp_ret_t ret = enRet::SUCCESS;

  nbsp_adc_value_t value = 0;

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  adc::ADC adc(0);

  ret = adc.selectStragetry(enDrvType::SEMA);

  if (ret != enRet::SUCCESS) {
    return 1;
  }


  ret = adc.getValue(&value);

  if (ret != enRet::SUCCESS) {
    return 1;
  }

  return 0;
}
