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

#include <vector>

#include <neuron/platform/types.hpp>
#include <neuron/gpio/gpio.hpp>

using namespace neuron;

int main(int /*argc*/, char* /*argv*/[])
{
  nbsp_ret_t ret = enRet::SUCCESS;
  nbsp_gpio_dir_t dir;
  nbsp_gpio_resistance_t resist;
  nbsp_gpio_value_t value;
  gpio::GPIO pin(0);

  ret = pin.selectStragetry(enDrvType::SEMA);

  if (ret != enRet::SUCCESS) {
    return 1;
  }

  ret = pin.setResistance(gpio::enResistance::PULL_DOWN);

  if (ret != enRet::SUCCESS) {
    return 1;
  }

  ret = pin.getResistance(&resist);

  if (ret != enRet::SUCCESS) {
  }


  ret = pin.setDir(gpio::enDIR::OUTPUT);
  if (ret != enRet::SUCCESS) {
    return 1;
  }

  ret = pin.getDir(&dir);
  if (ret != enRet::SUCCESS) {
    return 1;
  }

  ret = pin.setValue(gpio::enValue::HIGH);

  if (ret != enRet::SUCCESS) {
    return 1;
  }

  ret = pin.setDir(gpio::enDIR::INPUT);

  if (ret != enRet::SUCCESS) {
    return 1;
  }

  ret = pin.getValue(&value);

  if (ret != enRet::SUCCESS) {
    return 1;
  }

  return 0;
}
