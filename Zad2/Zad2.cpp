
#include <iostream>
using namespace std;
#include"Segment.h"

int main()
{

  /*
  Segment seg;
  cout << "Podaj wsp odcinka x1 y1 x2 y2: ";
  cin >> seg;
  cout << "Podaj kat obrotu w stopniach: " ;
  int alpha = 0;
  cin >> alpha;

  cout << "Obrot odcinka: " << seg << " o kat " << alpha << endl;
  seg.Rotate( alpha );
  cout << " == " << seg << endl;
  */
  

  Segment seg1( Point( 1, 1 ), Point( 2, 2 ) );
  cout << "seg1 = " << seg1 ;

  cout << "Podaj wspolrzedne koncow odc x1 y1 x2 y2 : ";
  cin >> seg1;
  cout << "seg1 = " << seg1;

  cout << "Podaj kat brotu w stopniach: ";
  int alpha = 0;
  cin >> alpha;

  cout << "Obrot odcinka: " << seg1 << "o kat " << alpha;
  seg1.Rotate( alpha );
  cout << " == " << seg1 << endl;

  Segment seg2( seg1 );
  cout << "seg2 = " << seg2 << endl;
  
  
  
  return 0;
}
// 2 klasy w jednym pliku nag³ówkowym
// jedna taka w ktorej wszystko bedzie publiczne ( definiujemy jako strukture)


/*
    zdefiniowac klase Point dla reprezentacji punktow na plaszczyznie kartezjanskiej
  z calym interfejsem publicznym (struktura)
      - skladowe  mx, my  typu double
      - settery ( setX(), setY(), setPoint()  )
      - gettery
      - operatory we/wy   (wy: [1,2] ) (we:  4 5 )
      - konstruktor domyslny i z parametrami,
      - metoda Turn( double alpha ) //alpha kat w radianach
        (obrot punktu wokol poczatku ukladu)
      - przesuniecie punktu - Move( wsp wektora ) o wektor zdefiniowany koncem wektora

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

        - zdefiniowac PI jako stala preproces  3.14159265358979
      */