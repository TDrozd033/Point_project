#include "Segment.h"
#include<iostream>
/*
Point::Point()
{
  setPoint( 0, 0 );
}*/

Point::Point( const Point& p ) 
{
  *this = p;
}
Point:: Point( double x, double y ) 
{
  setPoint( x, y );
}


//
void Point::Move( double vx, double vy ) //przesuniecie punktu - Move( wsp wektora ) o wektor zdefiniowany koncem wektora
{
  setX( getX() + vx);
  setY( getY() + vy);
}

void Point::Move( const Point& v )
{
  setX( getX() + v.getX() );
  setY( getY() + v.getY() );
}




//
void Point::Turn( double alpha ) // kat w radianach , obrot punktu wokol poczatku ukladu
{
  Point p( *this );
  setX( p.getX() * cos( alpha ) - p.getY() * sin( alpha ) );
  setY( p.getX() * sin( alpha ) + p.getY() * cos( alpha ) );
 /*
  double stary_x = getX();
  double stary_y = getY();

// obracamy
  setX( stary_x * cos( alpha ) - stary_y * sin( alpha ) );
  setY( stary_y * cos( alpha ) - stary_x * sin( alpha ) );
  */
}


//
ostream& operator <<( ostream& out, const Point& p )
{
  out << "( " << p.mx << ", " << p.my << " )";
  return out;
}
//
istream& operator >> ( istream& in,  Point& p )
{
  /*
  char c;
  double x, y;
  in >> x >> c >> y >> c;
  p.setX( x );
  p.setY( y );
  */
  double x;

  in >> x;
  p.setX( x );
  in >> x; 
  p.setY( x );
  return in;


}


/*
Segment:: Segment()
{
  setSegm( 0, 0, 0, 0 );
}*/
Segment::Segment( const Segment& s )
{
  *this = s;
}
Segment:: Segment( double x1, double y1, double x2, double y2 )
{
  setSegm( x1, y1, x2, y2 );
}
Segment::Segment( const Point& pt1, const Point& pt2 )
{
  setPt1( pt1 );
  setPt2( pt2 );
}


Segment& Segment::operator = ( const Segment& segm )
{
  mPt1 = segm.getPt1();
  mPt2 = segm.getPt2();
  return *this;
}




void Segment::setPt1( const Point& pt )
{
  setPt1( pt.getX(), pt.getY() );
}



void Segment::setPt2( const Point& pt )
{
  setPt2( pt.getX(), pt.getY() );
}


void Segment::setSegm( const Point& pt1, const Point& pt2 )
{
  setPt1( pt1 );
  setPt2( pt2 );
}

void Segment::setSegm( const Segment& segm )
{
  mPt1.setPoint( segm.getPt1().getX(), segm.getPt1().getY() );
  mPt2.setPoint( segm.getPt2().getX(), segm.getPt2().getY() );
}


void Segment::Move( const Point& pt )
{
  mPt1.Move( pt );
  mPt2.Move( pt );
}
//
void Segment:: Move( double vx, double vy ) //Move( wsp wekt v ),  v - wektor zdefiniowany punktem (koncem wektora)
{
  setPt1( mPt1.mx + vx, mPt1.my + vy );
  setPt2( mPt2.mx + vx, mPt2.my + vy );

}
//
void Segment:: Rotate( int alpha ) // alpha kat w stopniach   // obraca odcinek wzgledem srodka odcinka
{

  Point v = srodekOdcinka(); // szukamy srodka odcinka 
  Move( v.getX() * ( -1 ), v.getY() * ( -1 ) ); // przesuwamy wszystkie punkty o wartosc przeciwna do wsp srodka odcinka 
  // obracamy przy uzyciu funkcji Turn o kat alpha 
  mPt1.Turn( Stopnie_na_radiany( alpha ) );
  mPt2.Turn( Stopnie_na_radiany( alpha ) );
  //przesuwamy spowrotem punkty -> odcinek obrocony o kat alpha wzgledem swojego srodka 
  Move( v.getX(), v.getY() );

}

//
 ostream& operator <<( ostream& out, const Segment& p )
{
   out << p.getPt1() << " -- " << p.getPt2() << endl;
   return out;

}

 //
istream& operator >> ( istream& in, Segment& p )
{
  Point nPt;
  in >> nPt; 
  p.setPt1( nPt );
  in >> nPt; 
  p.setPt2( nPt );
  return in;
}


//
Point Segment::srodekOdcinka() // do obliczenia wspolrzednych srodka odcinka // uzywamy funkcji srednia 
{
  double srodek_X = srednia( mPt1.getX(), mPt2.getX() );
  double srodek_Y = srednia( mPt1.getY(), mPt2.getY() );

  return Point( srodek_X, srodek_Y );

}
// zamiana stopni 
// 2pi = 360
//pi =180
// 180 - pi
//  stopnie - x
// 180x = pi*stopnie
// x = (pi* stopnie)/ 180



//this - do dostepu do bie¿¹cego obiektu w metodach i umo¿liwia operacje na jego sk³adowych lub zwracanie siebie samego
//setPt1