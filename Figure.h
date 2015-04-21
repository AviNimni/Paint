
#pragma once   

            
class Figure: public CObject
{
	
	DECLARE_SERIAL (Figure)     
public:
	void Serialize (CArchive& ar)
	{
		CObject::Serialize (ar);
		if (ar.IsStoring ())
		{
			ar << x1;
			ar << x2;
			ar << y1;
			ar << y2;
			ar << FigureColor;
			
		}
		else 
		{
			ar >> x1;
			ar >> x2;
			ar >> y1;
			ar >> y2;
			ar >> FigureColor;
		}
	}
	
protected:
public:
	int x1,y1,x2,y2;
	DWORD FigureColor;
	Figure();
	Figure(int xx1,int yy1, int xx2, int yy2,DWORD FigColor)
	{
		x1=xx1;
		x2=xx2;
		y1=yy1;
		y2=yy2;
		FigureColor=FigColor;
	}
	void SetColor(DWORD FigColor){FigureColor=FigColor;}
	DWORD GetColor() const {return FigureColor;}
	virtual int GetFig(){return -1;}
	virtual void Draw(CDC *dc){}
	virtual ~Figure(void);
	virtual void MouseMove(CPoint,CPoint,CDC*){}
};

class RectangleM:public Figure{
	DECLARE_SERIAL (RectangleM)  
public:
	RectangleM();
	RectangleM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor)
		:Figure(xx1,yy1,xx2,yy2,FigColor){}
	int GetFig(){return 0;};
	void Draw(CDC *dc)
	{
		CBrush myBrush;
		myBrush.CreateSolidBrush(FigureColor);
		dc->SelectObject(&myBrush);
		dc->Rectangle(x1,y1,x2,y2);
	}
	void MouseMove(CPoint startP,CPoint endP,CDC *dc)
	{
		int deltax,deltay;
		deltax=endP.x-startP.x;
		deltay=endP.y-startP.y;
		dc->Rectangle(x1+deltax,y1+deltay,x2+deltax,y2+deltay);
	}
};
class EllipseM:public Figure{

	DECLARE_SERIAL (EllipseM)    

public:
	EllipseM(); 
	EllipseM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor)
		:Figure(xx1,yy1,xx2,yy2,FigColor){}
	int GetFig(){return 2;}
	void Draw(CDC *dc)
	{
		CBrush myBrush;
		myBrush.CreateSolidBrush(FigureColor);
		dc->SelectObject(&myBrush);
		dc->Ellipse(x1,y1,x2,y2);
	}
	void MouseMove(CPoint startP,CPoint endP,CDC *dc)
	{
		int deltax,deltay;
		deltax=endP.x-startP.x;
		deltay=endP.y-startP.y;
		dc->Ellipse(x1+deltax,y1+deltay,x2+deltax,y2+deltay);
	}
	
};
class PolygonM : public Figure{
public:
	PolygonM();
	PolygonM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor):Figure(xx1,yy1,xx2,yy2,FigColor)
	{
		
	}
	virtual void Draw(CDC *dc) = 0;
	virtual void MouseMove(CPoint,CPoint,CDC*){};
};

class TriangleM : public PolygonM{

	DECLARE_SERIAL (TriangleM)
public:
	CPoint p[3];
	TriangleM();
	TriangleM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor):PolygonM(xx1,yy1,xx2,yy2,FigColor){}
	int GetFig(){return 4;}
	void Draw(CDC *dc)
	{
		p[0].x=x1;
		p[0].y=y2;
		p[1].x=x2;
		p[1].y=y2;
		p[2].x=(x1+x2)/2;
		p[2].y=y1;
		CBrush myBrush;
		myBrush.CreateSolidBrush(FigureColor);
		dc->SelectObject(&myBrush);
		dc->Polygon(p,3);
	}
	void MouseMove(CPoint startP,CPoint endP,CDC *dc)
	{
		int deltax,deltay;
		deltax=endP.x-startP.x;
		deltay=endP.y-startP.y;
		p[0].x=x1+deltax;
		p[0].y=y2+deltay;
		p[1].x=x2+deltax;
		p[1].y=y2+deltay;
		p[2].x=(x1+deltax+x2+deltax)/2;
		p[2].y=y1+deltay;
		dc->Polygon(p,3);
	}
};

class ArrowM : public PolygonM{

	DECLARE_SERIAL (ArrowM)
public:
	CPoint p[7];
	ArrowM();
	ArrowM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor):PolygonM(xx1,yy1,xx2,yy2,FigColor){}
	int GetFig(){return 7;}
	void Draw(CDC *dc)
	{
		p[0].x=x1;
		p[0].y=((y1+y2)/2+y1)/2;
		p[1].x=x1;
		p[1].y=((y1+y2)/2+y2)/2;
		p[2].x=(x1+x2)/2;
		p[2].y=((y1+y2)/2+y2)/2;
		p[3].x=(x1+x2)/2;
		p[3].y=y2;
		p[4].x=x2;
		p[4].y=(y1+y2)/2;
		p[5].x=(x1+x2)/2;
		p[5].y=y1;
		p[6].x=(x1+x2)/2;
		p[6].y=((y1+y2)/2+y1)/2;
		CBrush myBrush;
		myBrush.CreateSolidBrush(FigureColor);
		dc->SelectObject(&myBrush);
		dc->Polygon(p,7);
	}
	void MouseMove(CPoint startP,CPoint endP,CDC *dc)
	{
		int deltax,deltay;
		deltax=endP.x-startP.x;
		deltay=endP.y-startP.y;
		p[0].x=x1+deltax;
		p[0].y=((y1+deltay+y2+deltay)/2+y1+deltay)/2;
		p[1].x=x1+deltax;
		p[1].y=((y1+deltay+y2+deltay)/2+y2+deltay)/2;
		p[2].x=(x1+deltax+x2+deltax)/2;
		p[2].y=((y1+deltay+y2+deltay)/2+y2+deltay)/2;
		p[3].x=(x1+deltax+x2+deltax)/2;
		p[3].y=y2+deltay;
		p[4].x=x2+deltax;
		p[4].y=(y1+deltay+y2+deltay)/2;
		p[5].x=(x1+deltax+x2+deltax)/2;
		p[5].y=y1+deltay;
		p[6].x=(x1+deltax+x2+deltax)/2;
		p[6].y=((y1+deltay+y2+deltay)/2+y1+deltay)/2;
		dc->Polygon(p,7);
	}
};

class LineM : public Figure{
	DECLARE_SERIAL (LineM)
	public:
	LineM();
	LineM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor):Figure(xx1,yy1,xx2,yy2,FigColor){}
	void Draw(CDC *dc)
	{
		CPen myPen1(PS_SOLID, 2, FigureColor);
		CPen *oldPen;
		oldPen=dc->SelectObject( &myPen1 );
		dc->MoveTo(x1,y1);
		dc->LineTo(x2,y2);
		dc->SelectObject( oldPen ); 
	}
	int GetFig(){return 5;}
};
class PenM : public LineM{
	DECLARE_SERIAL (PenM)
	public:
	PenM();
	PenM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor):LineM(xx1,yy1,xx2,yy2,FigColor){}
	int GetFig(){return 6;}
};


class SquareM : public RectangleM{
	DECLARE_SERIAL (SquareM)
public:
	SquareM();
	SquareM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor):RectangleM(xx1,yy1,xx2,yy2,FigColor)
	{
		if(xx1<xx2)
			x2=xx1+abs(yy1-yy2);
		else
			x2=xx1-abs(yy1-yy2);
	}

	int GetFig(){return 1;}
};

class CircleM : public EllipseM{
	DECLARE_SERIAL (CircleM)
public:
	CircleM();
	CircleM(int xx1,int yy1, int xx2, int yy2,DWORD FigColor):EllipseM(xx1,yy1,xx2,yy2,FigColor)
	{
		if(xx1<xx2)
			x2=xx1+abs(yy1-yy2);
		else
			x2=xx1-abs(yy1-yy2);
	}
	int GetFig(){return 3;}
};