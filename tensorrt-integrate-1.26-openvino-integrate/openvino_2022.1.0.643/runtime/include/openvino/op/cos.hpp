// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include "openvino/op/util/unary_elementwise_arithmetic.hpp"

namespace ov {
namespace op {
namespace v0 {
/// \brief Elementwise cosine operation.
class OPENVINO_API Cos : public util::UnaryElementwiseArithmetic {
public:
    OPENVINO_OP("Cos", "opset1", util::UnaryElementwiseArithmetic);
    BWDCMP_RTTI_DECLARATION;

    /// \brief Constructs a cosine operation.
    Cos() = default;
    /// \brief Constructs a cosine operation.
    ///
    /// \param arg Node that produces the input tensor.
    Cos(const Output<Node>& arg);
    bool visit_attributes(AttributeVisitor& visitor) override;

    std::shared_ptr<Node> clone_with_new_inputs(const OutputVector& new_args) const override;
    OPENVINO_SUPPRESS_DEPRECATED_START
    bool evaluate(const HostTensorVector& outputs, const HostTensorVector& inputs) const override;
    OPENVINO_SUPPRESS_DEPRECATED_END
    bool has_evaluate() const override;
};
}  // namespace v0
}  // namespace op
}  // namespace ov
