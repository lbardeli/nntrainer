// SPDX-License-Identifier: Apache-2.0
/**
 * Copyright (C) 2020 Parichay Kapoor <pk.kapoor@samsung.com>
 *
 * @file	sgd.cpp
 * @date	6 October 2020
 * @see		https://github.com/nnstreamer/nntrainer
 * @author	Jijoong Moon <jijoong.moon@samsung.com>
 * @author	Parichay Kapoor <pk.kapoor@samsung.com>
 * @bug		No known bugs except for NYI items
 * @brief	This is the SGD optimizer.
 */

#include <sgd.h>

namespace nntrainer {

const std::string SGD::type = "sgd";

void SGD::apply_gradient(Weight &weight, double updated_lr, int iteration) {
  Tensor &x = weight.getVariableRef();
  const Tensor &x_grad = weight.getGradientRef();
  x.add_i(x_grad, -updated_lr);
}

} // namespace nntrainer
