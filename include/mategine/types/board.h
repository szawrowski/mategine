// Copyright (c) 2024, Alexander Szawrowski
//
// This file is distributed under the MIT License.
// See LICENSE file for details.

#ifndef MATEGINE_TYPES_BOARD_H_
#define MATEGINE_TYPES_BOARD_H_

#include <array>
#include <vector>

#include "mategine/types/move.h"
#include "mategine/types/piece.h"
#include "mategine/types/position.h"

namespace mategine {

class Board {
public:
  Board() {
    for (int row = 2; row < 6; ++row) {
      for (int col = 0; col < 8; ++col) {
        board_[row][col] = Piece(PieceType::kEmpty, Color::kNone);
      }
    }

    for (int col = 0; col < 8; ++col) {
      SetPiece({1, col}, Piece(PieceType::kPawn, Color::kWhite));
      SetPiece({6, col}, Piece(PieceType::kPawn, Color::kBlack));
    }

    SetPiece({0, 0}, Piece(PieceType::kRook, Color::kWhite));
    SetPiece({0, 7}, Piece(PieceType::kRook, Color::kWhite));
    SetPiece({7, 0}, Piece(PieceType::kRook, Color::kBlack));
    SetPiece({7, 7}, Piece(PieceType::kRook, Color::kBlack));

    SetPiece({0, 1}, Piece(PieceType::kKnight, Color::kWhite));
    SetPiece({0, 6}, Piece(PieceType::kKnight, Color::kWhite));
    SetPiece({7, 1}, Piece(PieceType::kKnight, Color::kBlack));
    SetPiece({7, 6}, Piece(PieceType::kKnight, Color::kBlack));

    SetPiece({0, 2}, Piece(PieceType::kBishop, Color::kWhite));
    SetPiece({0, 5}, Piece(PieceType::kBishop, Color::kWhite));
    SetPiece({7, 2}, Piece(PieceType::kBishop, Color::kBlack));
    SetPiece({7, 5}, Piece(PieceType::kBishop, Color::kBlack));

    SetPiece({0, 3}, Piece(PieceType::kQueen, Color::kWhite));
    SetPiece({7, 3}, Piece(PieceType::kQueen, Color::kBlack));

    SetPiece({0, 4}, Piece(PieceType::kKing, Color::kWhite));
    SetPiece({7, 4}, Piece(PieceType::kKing, Color::kBlack));
  }

  [[nodiscard]] Piece GetPiece(const Position pos) const {
    return board_[pos.row][pos.col];
  }

  void SetPiece(const Position pos, const Piece piece) {
    board_[pos.row][pos.col] = piece;
  }

  [[nodiscard]] bool IsValidMove(const Move move) const {
    if (GetPiece(move.from).GetType() == PieceType::kEmpty) {
      return false;
    }
    switch (GetPiece(move.from).GetType()) {
      case PieceType::kPawn:
        return IsValidPawnMove(move);
      case PieceType::kRook:
        return IsValidRookMove(move);
      case PieceType::kKnight:
        return IsValidKnightMove(move);
      case PieceType::kBishop:
        return IsValidBishopMove(move);
      case PieceType::kQueen:
        return IsValidQueenMove(move);
      case PieceType::kKing:
        return IsValidKingMove(move);
      default:
        return false;
    }
  }

  [[nodiscard]] std::vector<Move> GetValidMoves(const Position pos) const {
    std::vector<Move> moves;
    switch (GetPiece(pos).GetType()) {
      case PieceType::kPawn:
        moves = GetValidPawnMoves(pos);
        break;
      case PieceType::kRook:
        moves = GetValidRookMoves(pos);
        break;
      case PieceType::kKnight:
        moves = GetValidKnightMoves(pos);
        break;
      case PieceType::kBishop:
        moves = GetValidBishopMoves(pos);
        break;
      case PieceType::kQueen:
        moves = GetValidQueenMoves(pos);
        break;
      case PieceType::kKing:
        moves = GetValidKingMoves(pos);
        break;
      default:
        break;
    }
    return moves;
  }

  [[nodiscard]] bool IsCheckmate() const {
    return false;
  }

  [[nodiscard]] bool IsStalemate() const {
    return false;
  }

private:
  [[nodiscard]] bool IsValidPawnMove(Move move) const;
  [[nodiscard]] bool IsValidRookMove(Move move) const;
  [[nodiscard]] bool IsValidKnightMove(Move move) const;
  [[nodiscard]] bool IsValidBishopMove(Move move) const;
  [[nodiscard]] bool IsValidQueenMove(Move move) const;
  [[nodiscard]] bool IsValidKingMove(Move move) const;

  [[nodiscard]] std::vector<Move> GetValidPawnMoves(Position pos) const;
  [[nodiscard]] std::vector<Move> GetValidRookMoves(Position pos) const;
  [[nodiscard]] std::vector<Move> GetValidKnightMoves(Position pos) const;
  [[nodiscard]] std::vector<Move> GetValidBishopMoves(Position pos) const;
  [[nodiscard]] std::vector<Move> GetValidQueenMoves(Position pos) const;
  [[nodiscard]] std::vector<Move> GetValidKingMoves(Position pos) const;

private:
  std::array<std::array<Piece, 8>, 8> board_{};
};

}  // namespace mategine

#endif  // MATEGINE_TYPES_BOARD_H_
