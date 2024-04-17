#include "Errors.h"
#include "Move.h"

// Space for implementing Move functions.
Move::Move(const std::string &input)
{
    // Parse the input string to initialize the Move.
    // The input string will be in the format "number player square [comment]".

    /*
    Move Format
    A move is represented as a single line of text in the following format. The term "whitespace" means one or more characters that are considered spaces by the isspace() function from the cctype header and/or the std::ws helper from the istream header.

    The move number. This is an integer between 1 and 9, inclusive, with no sign.
    Whitespace.
    The player code. This is either an X or an O; lower case is also allowed.
    Whitespace.
    The square code. This is a letter followed by a digit. Letters represent rows, with row A being the top row, B the middle, and C the bottom; lower case is also allowed. Digits represent columns, with 1 being the left column, 2 the middle, and 3 the right.
    Optionally, whitespace.
    Optionally, a comment. This is any text beginning with the # character and extending to the end of the string. If a comment is present, the preceding whitespace is required.
    When printing moves, your program should use the same format. When whitespace is required, it should always print a single space character. It should never print comments or the whitespace that precedes them. Player and row codes should be in upper case.
    */

    std::istringstream iss(input);

    // whitespace represents by std::ws
    iss >> number >> std::ws >> player >> std::ws >> row >> column;
    player = std::toupper(player);
    row = std::toupper(row);

    // Check if there is more to read and a comment marker
    if (iss >> std::ws && iss.peek() == '#')
    {
        std::getline(iss, comment); // Extract the comment
    }
}

// Convert Move object back to a string in the correct format
std::string Move::to_string() const
{
    std::ostringstream oss;
    oss << number << " " << player << " " << row << column;
    if (!comment.empty())
    {
        oss << " " << comment;
    }
    return oss.str();
}