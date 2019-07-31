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
#include <array>

#include <neuron/platform/types.hpp>
#include <neuron/spi/spi.hpp>

using namespace neuron;

int main(int /*argc*/, char* /*argv*/[])
{
  std::array<unsigned char, 10> tx_buf;
  std::array<unsigned char, 10> rx_buf;

  nbsp_ret_t ret = enRet::SUCCESS;

  struct spi::SPIInfo_t spi_info;
  spi_info.port = 0;
  spi_info.byte_order = spi::enORDER::LSB_FIRST;
  spi_info.phase = spi::enPHASE::PHASE_0;
  spi_info.polarity = spi::enPOLARITY::POLARITY_0;
  spi_info.freq = 16000000;

  spi::SPI spi_channel(&spi_info, enDrvType::NATIVE);

  ret = spi_channel.transfer(tx_buf.data(), tx_buf.size(), rx_buf.data(), rx_buf.size());

  if (ret != enRet::SUCCESS) {
    return 1;
  }

  return 0;
}
