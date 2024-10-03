#include "pieces.h"
#include "../definitions.h"
#include "../chessboard.h"
#include <stdio.h>
#include <stdlib.h>

int pawn_rules(move m, p pieces[])
{
    int board[BOARD_SIZE][BOARD_SIZE];
    getBoard(pieces, board);

    int deltaY = abs(m.start_y - m.dest_y);
    int deltaX = abs(m.start_x - m.dest_x);

    if(m.piece < 16 && (m.direction == DOWNLEFT || m.direction == DOWNRIGHT))
    {
        if(deltaX == 1 && deltaY == 1)
        {
            if(board[m.dest_x][m.dest_y] != EMPTY_COORDINATE)
                return 1;
            else return 0;
        }
        else return 0;
    }
    else if(m.piece >= 16 && (m.direction == UPLEFT || m.direction == UPRIGHT))
    {
        if(deltaX == 1 && deltaY == 1)
        {
            if(board[m.dest_x][m.dest_y] != EMPTY_COORDINATE)
                return 1;
            else return 0;
        }
        else return 0;
    }

    int steps;
    if(m.piece < 16 && pieces[m.piece].y == 1)
    {
        steps = 2;
    }
    else if(m.piece >= 16 && pieces[m.piece].y == 6)
    {
        steps = 2;
    }
    else steps = 1;

    if(m.piece < 16 && (-(m.start_y - m.dest_y) <= steps && -(m.start_y - m.dest_y) > 0) && (m.start_x - m.dest_x) == 0)
    {
        if(board[m.dest_x][m.dest_y] == EMPTY_COORDINATE)
        {
            if(m.dest_y == 7) pieces[m.piece].state = PROMOTED;
            return 1;
        }
            
        else return 0;
    }
    else if(m.piece >= 16 && ((m.start_y - m.dest_y) <= steps && (m.start_y - m.dest_y) > 0) && (m.start_x - m.dest_x) == 0)
    {
        if(board[m.dest_x][m.dest_y] == EMPTY_COORDINATE)
        {
            if(m.dest_y == 0) pieces[m.piece].state = PROMOTED;
            return 1;
        }
            
        else return 0;
    }
    else return 0;
}