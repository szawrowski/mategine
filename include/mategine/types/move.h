// Copyright (c) 2024, Alexander Szawrowski
//
// This file is distributed under the MIT License.
// See LICENSE file for details.

#ifndef MATEGINE_TYPES_MOVE_H_
#define MATEGINE_TYPES_MOVE_H_

#include "mategine/types/position.h"

namespace mategine {

struct Move {
  Position from;
  Position to;
};

}  // namespace mategine

#endif  // MATEGINE_TYPES_MOVE_H_
