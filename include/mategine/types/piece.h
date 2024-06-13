// Copyright (c) 2024, Alexander Szawrowski
//
// This file is distributed under the MIT License.
// See LICENSE file for details.

#ifndef MATEGINE_TYPES_PIECE_H_
#define MATEGINE_TYPES_PIECE_H_

#include "mategine/types/color.h"
#include "mategine/types/piece_type.h"

namespace mategine {

class Piece {
public:
  Piece(PieceType type, Color color) : type_(type), color_(color) {}

  PieceType GetType() const { return type_; }
  Color GetColor() const { return color_; }

private:
  PieceType type_;
  Color color_;
};

}  // namespace mategine

#endif  // MATEGINE_TYPES_PIECE_H_
