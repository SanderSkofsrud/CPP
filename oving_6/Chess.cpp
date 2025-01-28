#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ChessBoard {
public:
    enum class Color { WHITE, BLACK };

    class Piece {
    public:
        Piece(Color color) : color(color) {}
        virtual ~Piece() {}

        Color color;
        string color_string() const {
            return (color == Color::WHITE) ? "white" : "black";
        }

        virtual string type() const = 0;
        virtual string short_type() const = 0;
        virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;
    };

    class King : public Piece {
    public:
        King(Color color_) : Piece(color_) {}
        string type() const override {
            return color_string() + " king";
        }
        string short_type() const override {
            return (color == Color::WHITE) ? "♔" : "♚";
        }
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return abs(from_x - to_x) <= 1 && abs(from_y - to_y) <= 1;
        }
    };

    class Knight : public Piece {
    public:
        Knight(Color color_) : Piece(color_) {}
        string type() const override {
            return color_string() + " knight";
        }
        string short_type() const override {
            return (color == Color::WHITE) ? "♘" : "♞";
        }
        bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
            return (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1) ||
                   (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2);
        }
    };

    ChessBoard() {
        squares.resize(8);
        for (auto &column : squares) {
            column.resize(8);
        }
    }

    vector<vector<unique_ptr<Piece>>> squares;
    function<void(const vector<vector<unique_ptr<Piece>>> &)> after_piece_move;

    // Funksjon for å flytte brikker
    bool move_piece(const std::string &from, const std::string &to) {
        int from_x = from[0] - 'a';
        int from_y = stoi(string(1, from[1])) - 1;
        int to_x = to[0] - 'a';
        int to_y = stoi(string(1, to[1])) - 1;

        auto &piece_from = squares[from_x][from_y];
        if (piece_from && piece_from->valid_move(from_x, from_y, to_x, to_y)) {
            auto &piece_to = squares[to_x][to_y];
            piece_to = std::move(piece_from);  // Flytter eierskapet med std::move
            if (after_piece_move) after_piece_move(squares);  // Kaller lambda etter at trekket er gjort
            return true;
        }
        return false;
    }
};

class ChessBoardPrint {
public:
    ChessBoardPrint(ChessBoard &board) {
        board.after_piece_move = [](const vector<vector<unique_ptr<ChessBoard::Piece>>> &squares) {
            cout << "ChessBoard state:" << endl;
            for (int row = 7; row >= 0; --row) {
                cout << row + 1 << " ";
                for (int col = 0; col < 8; ++col) {
                    if (squares[col][row])
                        cout << squares[col][row]->short_type() << " ";
                    else
                        cout << ". ";
                }
                cout << endl;
            }
            cout << "  a b c d e f g h" << endl;
        };
    }
};

int main() {
    ChessBoard board;
    ChessBoardPrint print(board);

    // Setter opp brettet med noen brikker
    board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
    board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);

    board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
    board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

    // Flytter noen brikker
    board.move_piece("e1", "e2");
    board.move_piece("b1", "c3");

    return 0;
}
