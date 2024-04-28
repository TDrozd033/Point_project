#pragma once
#include <iostream>
#include<cmath>

using namespace std;
#define PI 3.141592653589793

//ZADANIE:
//ww klasie punktu i klasie odcinka usuwamy konstruktor domyslny
// dodajemy parametry domyslne
// dodajemy konstruktor kopiujacy
// settery i gettery wrzucamy do odpowiedniej klasy 
/*
zdefiniowac klase Point dla reprezentacji punktow na plaszczyznie kartezjanskiej
z calym interfejsem publicznym( struktura )
- skladowe  mx, my  typu double
- settery( setX(), setY(), setPoint() )
- gettery
- operatory we / wy( wy: [1, 2] ) ( we:  4 5 )
- konstruktor domyslny i z parametrami,
-metoda Turn( double alpha ) //alpha kat w radianach
( obrot punktu wokol poczatku ukladu )
- przesuniecie punktu - Move( wsp wektora ) o wektor zdefiniowany koncem wektora
*/
struct Point
{
public:
  //Point();
  Point( double x=0, double y=0 ); // konstruktor domyslny
  Point( const Point& p ); // konstruktor kopiujacy 

  void setX( double x );
  void setY( double y );

  void setPoint( double x, double y ); // punkt na podstawie x i y 
  void setPoint( const Point& pt ); // new     //ustaw punkt przekazujac mu punkt

  double getX() const;
  double getY() const;

  void Move( double vx, double vy );
  void Move( const Point& v ); //new  // przesuniecie o wektor reprezentowany przez punkt

  void Turn( double alpha ); // kat w radianach

  // operatory wejscia i wyjcsia
 friend ostream& operator <<( ostream& out, const Point& p );
  friend istream& operator >> ( istream& in,  Point& p );

  //wspolrzedne punktu
  double mx;
  double my;

};


// INLINE FUNCTIONS

inline void Point::setX( double x )
{
  mx = x;
}
inline void Point::setY( double y )
{
  my = y;
}


inline double Point::getX()const
{
  return mx;
}
inline double Point::getY()const
{
  return my;
}
// ustawienie punktow na podstawie wspolrzednych
inline void Point::setPoint( double x, double y )
{
  setX( x );
  setY( y );
}
// ustawienie na podstawie innego pkt
inline void Point::setPoint( const Point& pt )
{
  setX( pt.getX() );
  setY( pt.getY() );

}




/*
zdefiniowac klase Segment dla reprezentacji odcinkow
      - skladowe dwa punkty (konce odcinkow  mPt1, mPt2)
      - settery ( setPt1(), setPt2() , setSegm()  )
      - gettery  // const Point& getPt1() const        implem:  { return mPt1; }
      - operatory we/wy ( [1,2]--[-3,5] )
    - konstruktor domyslny
      - konstruktor z parametrami (x1,y1,x2,y2)

      - publiczna metoda Move( wsp wekt v ),  v - wektor zdefiniowany punktem (koncem wektora)
      - publiczna metoda Rotate( int alpha )  // alpha kat w stopniach
          obraca odcinek wzgledem srodka odcinka

          prywatna metoda obliczajaca wsp srodka odcinka
      metoda prywatna liczaca srednia arytmertyczna
      metoda prywatna - konwersja stopni do radianow - zwracajace kat w radianach)

*/
class Segment
{
public:

  //Segment();
  // konstruktory
  Segment( double x1=0, double y1= 0, double x2 = 0, double y2 = 0 );
  Segment( const Point& pt1, const Point& pt2 ); // new
  Segment( const Segment& segm );

  Segment& operator = ( const Segment& segm ); //new     // operator podstawienia

  void setPt1( double x, double y ); // pierwszy koniec odcinka
  void setPt1( const Point& pt ); // new
  void setPt2( double x, double y ); // drugi koniec
  void setPt2( const Point& pt ); // new

  void setSegm( double x1, double y1, double x2, double y2 ); // skladowe obu koncow odcinka 
  void setSegm( const Point& pt1, const Point& pt2 ); //new
  void setSegm( const Segment& segm );// new


  const Point& getPt1() const;
  const Point& getPt2() const;


  void Move( double vx, double vy ); //Move( wsp wekt v ),  v - wektor zdefiniowany punktem (koncem wektora)
  void Move( const Point& pt ); // new        // przesuniecie o wektor wyznaczony przez x i y punktu


  void Rotate( int alpha ); // alpha kat w stopniach   // obraca odcinek wzgledem srodka odcinka

  // operatory wejscia i wyjscia
  friend ostream& operator <<( ostream& out, const Segment& p );
  friend istream& operator >> ( istream& in,  Segment& p );

private:
  double srednia( double a, double b );
  double Stopnie_na_radiany( int stopnie ); // zwraca kat w radianach
  Point srodekOdcinka(); // do obliczenia wspolrzednych srodka odcinka 

private:
  Point mPt1;
  Point mPt2;
  
};


//INLINE FUNCTIONS:
 
inline void Segment::setPt1( double x, double y ) // pierwszy koniec odcinka
{
  mPt1.setPoint( x, y );
}
inline void Segment::setPt2( double x, double y )// drugi koniec
{
  mPt2.setPoint( x, y );
}

inline void Segment::setSegm( double x1, double y1, double x2, double y2 ) // skladowe obu koncow odcinka 
{
  setPt1( x1, y1 );
  setPt2( x2, y2 );
}

inline const Point& Segment::getPt1() const
{
  return mPt1;

}
inline const Point& Segment::getPt2() const
{
  return mPt2;
}

inline double Segment::srednia( double a, double b )
{
  return ( a + b ) / 2;
}
inline double Segment::Stopnie_na_radiany( int stopnie ) // zwraca kat w radianach
{
  return ( PI * stopnie ) / 180;

}


//KLASA PUNKTU:
// najpierw zdefiniowac obie klasy 
// klasa pomocnicza - sruktura
// setPoint - wywolywanie setX i setY ( double)
// gettery - wylacznie dotycza skladowych x i y ( bez getPoint)
// funkcja obrotu wokol poczatku ukladu wspolrzednych - metoda turn - k¹t w radianach - dopisac w komentarzu
// move - wspolrzedne wektora przesuniecia zdefiniowany koncem wektora


//KLASA ODCINKA:
// gettery przepisac z polecenia zdefiniowanie
// 

// porzadek w klasie 
// // najpierw definiujemy struktury danych 
//najpierw publiczen konstruktory
//publiczne struktury danych
// prywatne konstruktory
// prywatne struktury danych 

// funkcja srednia a+b/2




