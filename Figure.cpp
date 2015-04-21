#include "stdafx.h"
#include "Figure.h"

IMPLEMENT_SERIAL (Figure, CObject, 1)
IMPLEMENT_SERIAL (RectangleM, CObject, 1)
IMPLEMENT_SERIAL (EllipseM, CObject, 1)
IMPLEMENT_SERIAL (TriangleM, CObject, 1)
IMPLEMENT_SERIAL (LineM, CObject, 1)
IMPLEMENT_SERIAL (SquareM, CObject, 1)
IMPLEMENT_SERIAL (CircleM, CObject, 1)
IMPLEMENT_SERIAL (PenM, CObject, 1)
IMPLEMENT_SERIAL (ArrowM, CObject, 1)

Figure::Figure(void)
{
}

Figure::~Figure(void)
{
}

RectangleM::RectangleM(){}
EllipseM::EllipseM(){}
TriangleM::TriangleM(){}
LineM::LineM(){}
PenM::PenM(){}
SquareM::SquareM(){}
CircleM::CircleM(){}
PolygonM::PolygonM(){}
ArrowM::ArrowM(){}