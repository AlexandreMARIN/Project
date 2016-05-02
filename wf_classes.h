#ifndef WF_CLASSES_H
#define WF_CLASSES_H

extern "C" {
#include "widefloat_float_types.h"
}


/*Declaration of all widefloat classes*/
class wf256_t;
class wf512_t;



/*classes definition*/

class wf256_t {
	widefloat_float256_t value;//value

	/*friendship between widefloat classes for constructors and assignments*/
	friend class wf512_t;
	public:
		//constructors
		  wf256_t();
		  wf256_t(const char &);
		  wf256_t(const signed char &);
		  wf256_t(const unsigned char &);
		  wf256_t(const int16_t &);
		  wf256_t(const uint16_t &);
		  wf256_t(const int32_t &);
		  wf256_t(const uint32_t &);
		  wf256_t(const int64_t &);
		  wf256_t(const uint64_t &);
		  wf256_t(const float &);
		  wf256_t(const double &);
		  wf256_t(const long double &);
		  wf256_t(const wf512_t &);


		/*Casts : only towards C++ types*/

		 operator char() const ;
		 operator signed char() const ;
		 operator unsigned char() const ;
		 operator int16_t() const ;
		 operator uint16_t() const ;
		 operator int32_t() const ;
		 operator uint32_t() const ;
		 operator int64_t() const ;
		 operator uint64_t() const ;
		 operator float() const ;
		 operator double() const ;
		 operator long double() const ;

		/*arithmetic operators as friend functions*/

		friend wf256_t operator+(const wf256_t &, const char &);
		friend wf256_t operator+(const wf256_t &, const signed char &);
		friend wf256_t operator+(const wf256_t &, const unsigned char &);
		friend wf256_t operator+(const wf256_t &, const int16_t &);
		friend wf256_t operator+(const wf256_t &, const uint16_t &);
		friend wf256_t operator+(const wf256_t &, const int32_t &);
		friend wf256_t operator+(const wf256_t &, const uint32_t &);
		friend wf256_t operator+(const wf256_t &, const int64_t &);
		friend wf256_t operator+(const wf256_t &, const uint64_t &);
		friend wf256_t operator+(const wf256_t &, const float &);
		friend wf256_t operator+(const wf256_t &, const double &);
		friend wf256_t operator+(const wf256_t &, const long double &);
		friend wf256_t operator+(const wf256_t &, const wf256_t &);
		friend wf512_t operator+(const wf256_t &, const wf512_t &);

		friend wf256_t operator+(const char &, const wf256_t &);
		friend wf256_t operator+(const signed char &, const wf256_t &);
		friend wf256_t operator+(const unsigned char &, const wf256_t &);
		friend wf256_t operator+(const int16_t &, const wf256_t &);
		friend wf256_t operator+(const uint16_t &, const wf256_t &);
		friend wf256_t operator+(const int32_t &, const wf256_t &);
		friend wf256_t operator+(const uint32_t &, const wf256_t &);
		friend wf256_t operator+(const int64_t &, const wf256_t &);
		friend wf256_t operator+(const uint64_t &, const wf256_t &);
		friend wf256_t operator+(const float &, const wf256_t &);
		friend wf256_t operator+(const double &, const wf256_t &);
		friend wf256_t operator+(const long double &, const wf256_t &);
		friend wf512_t operator+(const wf512_t &, const wf256_t &);

		friend wf256_t operator-(const wf256_t &, const char &);
		friend wf256_t operator-(const wf256_t &, const signed char &);
		friend wf256_t operator-(const wf256_t &, const unsigned char &);
		friend wf256_t operator-(const wf256_t &, const int16_t &);
		friend wf256_t operator-(const wf256_t &, const uint16_t &);
		friend wf256_t operator-(const wf256_t &, const int32_t &);
		friend wf256_t operator-(const wf256_t &, const uint32_t &);
		friend wf256_t operator-(const wf256_t &, const int64_t &);
		friend wf256_t operator-(const wf256_t &, const uint64_t &);
		friend wf256_t operator-(const wf256_t &, const float &);
		friend wf256_t operator-(const wf256_t &, const double &);
		friend wf256_t operator-(const wf256_t &, const long double &);
		friend wf256_t operator-(const wf256_t &, const wf256_t &);
		friend wf512_t operator-(const wf256_t &, const wf512_t &);

		friend wf256_t operator-(const char &, const wf256_t &);
		friend wf256_t operator-(const signed char &, const wf256_t &);
		friend wf256_t operator-(const unsigned char &, const wf256_t &);
		friend wf256_t operator-(const int16_t &, const wf256_t &);
		friend wf256_t operator-(const uint16_t &, const wf256_t &);
		friend wf256_t operator-(const int32_t &, const wf256_t &);
		friend wf256_t operator-(const uint32_t &, const wf256_t &);
		friend wf256_t operator-(const int64_t &, const wf256_t &);
		friend wf256_t operator-(const uint64_t &, const wf256_t &);
		friend wf256_t operator-(const float &, const wf256_t &);
		friend wf256_t operator-(const double &, const wf256_t &);
		friend wf256_t operator-(const long double &, const wf256_t &);
		friend wf512_t operator-(const wf512_t &, const wf256_t &);

		friend wf256_t operator*(const wf256_t &, const char &);
		friend wf256_t operator*(const wf256_t &, const signed char &);
		friend wf256_t operator*(const wf256_t &, const unsigned char &);
		friend wf256_t operator*(const wf256_t &, const int16_t &);
		friend wf256_t operator*(const wf256_t &, const uint16_t &);
		friend wf256_t operator*(const wf256_t &, const int32_t &);
		friend wf256_t operator*(const wf256_t &, const uint32_t &);
		friend wf256_t operator*(const wf256_t &, const int64_t &);
		friend wf256_t operator*(const wf256_t &, const uint64_t &);
		friend wf256_t operator*(const wf256_t &, const float &);
		friend wf256_t operator*(const wf256_t &, const double &);
		friend wf256_t operator*(const wf256_t &, const long double &);
		friend wf256_t operator*(const wf256_t &, const wf256_t &);
		friend wf512_t operator*(const wf256_t &, const wf512_t &);

		friend wf256_t operator*(const char &, const wf256_t &);
		friend wf256_t operator*(const signed char &, const wf256_t &);
		friend wf256_t operator*(const unsigned char &, const wf256_t &);
		friend wf256_t operator*(const int16_t &, const wf256_t &);
		friend wf256_t operator*(const uint16_t &, const wf256_t &);
		friend wf256_t operator*(const int32_t &, const wf256_t &);
		friend wf256_t operator*(const uint32_t &, const wf256_t &);
		friend wf256_t operator*(const int64_t &, const wf256_t &);
		friend wf256_t operator*(const uint64_t &, const wf256_t &);
		friend wf256_t operator*(const float &, const wf256_t &);
		friend wf256_t operator*(const double &, const wf256_t &);
		friend wf256_t operator*(const long double &, const wf256_t &);
		friend wf512_t operator*(const wf512_t &, const wf256_t &);

		friend wf256_t operator/(const wf256_t &, const char &);
		friend wf256_t operator/(const wf256_t &, const signed char &);
		friend wf256_t operator/(const wf256_t &, const unsigned char &);
		friend wf256_t operator/(const wf256_t &, const int16_t &);
		friend wf256_t operator/(const wf256_t &, const uint16_t &);
		friend wf256_t operator/(const wf256_t &, const int32_t &);
		friend wf256_t operator/(const wf256_t &, const uint32_t &);
		friend wf256_t operator/(const wf256_t &, const int64_t &);
		friend wf256_t operator/(const wf256_t &, const uint64_t &);
		friend wf256_t operator/(const wf256_t &, const float &);
		friend wf256_t operator/(const wf256_t &, const double &);
		friend wf256_t operator/(const wf256_t &, const long double &);
		friend wf256_t operator/(const wf256_t &, const wf256_t &);
		friend wf512_t operator/(const wf256_t &, const wf512_t &);

		friend wf256_t operator/(const char &, const wf256_t &);
		friend wf256_t operator/(const signed char &, const wf256_t &);
		friend wf256_t operator/(const unsigned char &, const wf256_t &);
		friend wf256_t operator/(const int16_t &, const wf256_t &);
		friend wf256_t operator/(const uint16_t &, const wf256_t &);
		friend wf256_t operator/(const int32_t &, const wf256_t &);
		friend wf256_t operator/(const uint32_t &, const wf256_t &);
		friend wf256_t operator/(const int64_t &, const wf256_t &);
		friend wf256_t operator/(const uint64_t &, const wf256_t &);
		friend wf256_t operator/(const float &, const wf256_t &);
		friend wf256_t operator/(const double &, const wf256_t &);
		friend wf256_t operator/(const long double &, const wf256_t &);
		friend wf512_t operator/(const wf512_t &, const wf256_t &);


		/*assignments (as members)*/
		 wf256_t operator= (const char &);
		 wf256_t operator= (const signed char &);
		 wf256_t operator= (const unsigned char &);
		 wf256_t operator= (const int16_t &);
		 wf256_t operator= (const uint16_t &);
		 wf256_t operator= (const int32_t &);
		 wf256_t operator= (const uint32_t &);
		 wf256_t operator= (const int64_t &);
		 wf256_t operator= (const uint64_t &);
		 wf256_t operator= (const float &);
		 wf256_t operator= (const double &);
		 wf256_t operator= (const long double &);
		 wf256_t operator= (const wf512_t &);


		/*extended assignments as friend functions*/
		friend wf256_t operator+=(wf256_t &, const char &);
		friend wf256_t operator+=(wf256_t &, const signed char &);
		friend wf256_t operator+=(wf256_t &, const unsigned char &);
		friend wf256_t operator+=(wf256_t &, const int16_t &);
		friend wf256_t operator+=(wf256_t &, const uint16_t &);
		friend wf256_t operator+=(wf256_t &, const int32_t &);
		friend wf256_t operator+=(wf256_t &, const uint32_t &);
		friend wf256_t operator+=(wf256_t &, const int64_t &);
		friend wf256_t operator+=(wf256_t &, const uint64_t &);
		friend wf256_t operator+=(wf256_t &, const float &);
		friend wf256_t operator+=(wf256_t &, const double &);
		friend wf256_t operator+=(wf256_t &, const long double &);
		friend wf256_t operator+=(wf256_t &, const wf256_t &);
		friend wf256_t operator+=(wf256_t &, const wf512_t &);

		friend char operator+=(char &, const wf256_t &);
		friend signed char operator+=(signed char &, const wf256_t &);
		friend unsigned char operator+=(unsigned char &, const wf256_t &);
		friend int16_t operator+=(int16_t &, const wf256_t &);
		friend uint16_t operator+=(uint16_t &, const wf256_t &);
		friend int32_t operator+=(int32_t &, const wf256_t &);
		friend uint32_t operator+=(uint32_t &, const wf256_t &);
		friend int64_t operator+=(int64_t &, const wf256_t &);
		friend uint64_t operator+=(uint64_t &, const wf256_t &);
		friend float operator+=(float &, const wf256_t &);
		friend double operator+=(double &, const wf256_t &);
		friend long double operator+=(long double &, const wf256_t &);
		friend wf512_t operator+=(wf512_t &, const wf256_t &);

		friend wf256_t operator-=(wf256_t &, const char &);
		friend wf256_t operator-=(wf256_t &, const signed char &);
		friend wf256_t operator-=(wf256_t &, const unsigned char &);
		friend wf256_t operator-=(wf256_t &, const int16_t &);
		friend wf256_t operator-=(wf256_t &, const uint16_t &);
		friend wf256_t operator-=(wf256_t &, const int32_t &);
		friend wf256_t operator-=(wf256_t &, const uint32_t &);
		friend wf256_t operator-=(wf256_t &, const int64_t &);
		friend wf256_t operator-=(wf256_t &, const uint64_t &);
		friend wf256_t operator-=(wf256_t &, const float &);
		friend wf256_t operator-=(wf256_t &, const double &);
		friend wf256_t operator-=(wf256_t &, const long double &);
		friend wf256_t operator-=(wf256_t &, const wf256_t &);
		friend wf256_t operator-=(wf256_t &, const wf512_t &);

		friend char operator-=(char &, const wf256_t &);
		friend signed char operator-=(signed char &, const wf256_t &);
		friend unsigned char operator-=(unsigned char &, const wf256_t &);
		friend int16_t operator-=(int16_t &, const wf256_t &);
		friend uint16_t operator-=(uint16_t &, const wf256_t &);
		friend int32_t operator-=(int32_t &, const wf256_t &);
		friend uint32_t operator-=(uint32_t &, const wf256_t &);
		friend int64_t operator-=(int64_t &, const wf256_t &);
		friend uint64_t operator-=(uint64_t &, const wf256_t &);
		friend float operator-=(float &, const wf256_t &);
		friend double operator-=(double &, const wf256_t &);
		friend long double operator-=(long double &, const wf256_t &);
		friend wf512_t operator-=(wf512_t &, const wf256_t &);

		friend wf256_t operator*=(wf256_t &, const char &);
		friend wf256_t operator*=(wf256_t &, const signed char &);
		friend wf256_t operator*=(wf256_t &, const unsigned char &);
		friend wf256_t operator*=(wf256_t &, const int16_t &);
		friend wf256_t operator*=(wf256_t &, const uint16_t &);
		friend wf256_t operator*=(wf256_t &, const int32_t &);
		friend wf256_t operator*=(wf256_t &, const uint32_t &);
		friend wf256_t operator*=(wf256_t &, const int64_t &);
		friend wf256_t operator*=(wf256_t &, const uint64_t &);
		friend wf256_t operator*=(wf256_t &, const float &);
		friend wf256_t operator*=(wf256_t &, const double &);
		friend wf256_t operator*=(wf256_t &, const long double &);
		friend wf256_t operator*=(wf256_t &, const wf256_t &);
		friend wf256_t operator*=(wf256_t &, const wf512_t &);

		friend char operator*=(char &, const wf256_t &);
		friend signed char operator*=(signed char &, const wf256_t &);
		friend unsigned char operator*=(unsigned char &, const wf256_t &);
		friend int16_t operator*=(int16_t &, const wf256_t &);
		friend uint16_t operator*=(uint16_t &, const wf256_t &);
		friend int32_t operator*=(int32_t &, const wf256_t &);
		friend uint32_t operator*=(uint32_t &, const wf256_t &);
		friend int64_t operator*=(int64_t &, const wf256_t &);
		friend uint64_t operator*=(uint64_t &, const wf256_t &);
		friend float operator*=(float &, const wf256_t &);
		friend double operator*=(double &, const wf256_t &);
		friend long double operator*=(long double &, const wf256_t &);
		friend wf512_t operator*=(wf512_t &, const wf256_t &);

		friend wf256_t operator/=(wf256_t &, const char &);
		friend wf256_t operator/=(wf256_t &, const signed char &);
		friend wf256_t operator/=(wf256_t &, const unsigned char &);
		friend wf256_t operator/=(wf256_t &, const int16_t &);
		friend wf256_t operator/=(wf256_t &, const uint16_t &);
		friend wf256_t operator/=(wf256_t &, const int32_t &);
		friend wf256_t operator/=(wf256_t &, const uint32_t &);
		friend wf256_t operator/=(wf256_t &, const int64_t &);
		friend wf256_t operator/=(wf256_t &, const uint64_t &);
		friend wf256_t operator/=(wf256_t &, const float &);
		friend wf256_t operator/=(wf256_t &, const double &);
		friend wf256_t operator/=(wf256_t &, const long double &);
		friend wf256_t operator/=(wf256_t &, const wf256_t &);
		friend wf256_t operator/=(wf256_t &, const wf512_t &);

		friend char operator/=(char &, const wf256_t &);
		friend signed char operator/=(signed char &, const wf256_t &);
		friend unsigned char operator/=(unsigned char &, const wf256_t &);
		friend int16_t operator/=(int16_t &, const wf256_t &);
		friend uint16_t operator/=(uint16_t &, const wf256_t &);
		friend int32_t operator/=(int32_t &, const wf256_t &);
		friend uint32_t operator/=(uint32_t &, const wf256_t &);
		friend int64_t operator/=(int64_t &, const wf256_t &);
		friend uint64_t operator/=(uint64_t &, const wf256_t &);
		friend float operator/=(float &, const wf256_t &);
		friend double operator/=(double &, const wf256_t &);
		friend long double operator/=(long double &, const wf256_t &);
		friend wf512_t operator/=(wf512_t &, const wf256_t &);



		/*comparisons*/
		friend bool operator<(const wf256_t &, const char &);
		friend bool operator<(const wf256_t &, const signed char &);
		friend bool operator<(const wf256_t &, const unsigned char &);
		friend bool operator<(const wf256_t &, const int16_t &);
		friend bool operator<(const wf256_t &, const uint16_t &);
		friend bool operator<(const wf256_t &, const int32_t &);
		friend bool operator<(const wf256_t &, const uint32_t &);
		friend bool operator<(const wf256_t &, const int64_t &);
		friend bool operator<(const wf256_t &, const uint64_t &);
		friend bool operator<(const wf256_t &, const float &);
		friend bool operator<(const wf256_t &, const double &);
		friend bool operator<(const wf256_t &, const long double &);
		friend bool operator<(const wf256_t &, const wf256_t &);
		friend bool operator<(const wf256_t &, const wf512_t &);

		friend bool operator<(const char &, const wf256_t &);
		friend bool operator<(const signed char &, const wf256_t &);
		friend bool operator<(const unsigned char &, const wf256_t &);
		friend bool operator<(const int16_t &, const wf256_t &);
		friend bool operator<(const uint16_t &, const wf256_t &);
		friend bool operator<(const int32_t &, const wf256_t &);
		friend bool operator<(const uint32_t &, const wf256_t &);
		friend bool operator<(const int64_t &, const wf256_t &);
		friend bool operator<(const uint64_t &, const wf256_t &);
		friend bool operator<(const float &, const wf256_t &);
		friend bool operator<(const double &, const wf256_t &);
		friend bool operator<(const long double &, const wf256_t &);
		friend bool operator<(const wf512_t &, const wf256_t &);

		friend bool operator>(const wf256_t &, const char &);
		friend bool operator>(const wf256_t &, const signed char &);
		friend bool operator>(const wf256_t &, const unsigned char &);
		friend bool operator>(const wf256_t &, const int16_t &);
		friend bool operator>(const wf256_t &, const uint16_t &);
		friend bool operator>(const wf256_t &, const int32_t &);
		friend bool operator>(const wf256_t &, const uint32_t &);
		friend bool operator>(const wf256_t &, const int64_t &);
		friend bool operator>(const wf256_t &, const uint64_t &);
		friend bool operator>(const wf256_t &, const float &);
		friend bool operator>(const wf256_t &, const double &);
		friend bool operator>(const wf256_t &, const long double &);
		friend bool operator>(const wf256_t &, const wf256_t &);
		friend bool operator>(const wf256_t &, const wf512_t &);

		friend bool operator>(const char &, const wf256_t &);
		friend bool operator>(const signed char &, const wf256_t &);
		friend bool operator>(const unsigned char &, const wf256_t &);
		friend bool operator>(const int16_t &, const wf256_t &);
		friend bool operator>(const uint16_t &, const wf256_t &);
		friend bool operator>(const int32_t &, const wf256_t &);
		friend bool operator>(const uint32_t &, const wf256_t &);
		friend bool operator>(const int64_t &, const wf256_t &);
		friend bool operator>(const uint64_t &, const wf256_t &);
		friend bool operator>(const float &, const wf256_t &);
		friend bool operator>(const double &, const wf256_t &);
		friend bool operator>(const long double &, const wf256_t &);
		friend bool operator>(const wf512_t &, const wf256_t &);

		friend bool operator<=(const wf256_t &, const char &);
		friend bool operator<=(const wf256_t &, const signed char &);
		friend bool operator<=(const wf256_t &, const unsigned char &);
		friend bool operator<=(const wf256_t &, const int16_t &);
		friend bool operator<=(const wf256_t &, const uint16_t &);
		friend bool operator<=(const wf256_t &, const int32_t &);
		friend bool operator<=(const wf256_t &, const uint32_t &);
		friend bool operator<=(const wf256_t &, const int64_t &);
		friend bool operator<=(const wf256_t &, const uint64_t &);
		friend bool operator<=(const wf256_t &, const float &);
		friend bool operator<=(const wf256_t &, const double &);
		friend bool operator<=(const wf256_t &, const long double &);
		friend bool operator<=(const wf256_t &, const wf256_t &);
		friend bool operator<=(const wf256_t &, const wf512_t &);

		friend bool operator<=(const char &, const wf256_t &);
		friend bool operator<=(const signed char &, const wf256_t &);
		friend bool operator<=(const unsigned char &, const wf256_t &);
		friend bool operator<=(const int16_t &, const wf256_t &);
		friend bool operator<=(const uint16_t &, const wf256_t &);
		friend bool operator<=(const int32_t &, const wf256_t &);
		friend bool operator<=(const uint32_t &, const wf256_t &);
		friend bool operator<=(const int64_t &, const wf256_t &);
		friend bool operator<=(const uint64_t &, const wf256_t &);
		friend bool operator<=(const float &, const wf256_t &);
		friend bool operator<=(const double &, const wf256_t &);
		friend bool operator<=(const long double &, const wf256_t &);
		friend bool operator<=(const wf512_t &, const wf256_t &);

		friend bool operator>=(const wf256_t &, const char &);
		friend bool operator>=(const wf256_t &, const signed char &);
		friend bool operator>=(const wf256_t &, const unsigned char &);
		friend bool operator>=(const wf256_t &, const int16_t &);
		friend bool operator>=(const wf256_t &, const uint16_t &);
		friend bool operator>=(const wf256_t &, const int32_t &);
		friend bool operator>=(const wf256_t &, const uint32_t &);
		friend bool operator>=(const wf256_t &, const int64_t &);
		friend bool operator>=(const wf256_t &, const uint64_t &);
		friend bool operator>=(const wf256_t &, const float &);
		friend bool operator>=(const wf256_t &, const double &);
		friend bool operator>=(const wf256_t &, const long double &);
		friend bool operator>=(const wf256_t &, const wf256_t &);
		friend bool operator>=(const wf256_t &, const wf512_t &);

		friend bool operator>=(const char &, const wf256_t &);
		friend bool operator>=(const signed char &, const wf256_t &);
		friend bool operator>=(const unsigned char &, const wf256_t &);
		friend bool operator>=(const int16_t &, const wf256_t &);
		friend bool operator>=(const uint16_t &, const wf256_t &);
		friend bool operator>=(const int32_t &, const wf256_t &);
		friend bool operator>=(const uint32_t &, const wf256_t &);
		friend bool operator>=(const int64_t &, const wf256_t &);
		friend bool operator>=(const uint64_t &, const wf256_t &);
		friend bool operator>=(const float &, const wf256_t &);
		friend bool operator>=(const double &, const wf256_t &);
		friend bool operator>=(const long double &, const wf256_t &);
		friend bool operator>=(const wf512_t &, const wf256_t &);

		friend bool operator==(const wf256_t &, const char &);
		friend bool operator==(const wf256_t &, const signed char &);
		friend bool operator==(const wf256_t &, const unsigned char &);
		friend bool operator==(const wf256_t &, const int16_t &);
		friend bool operator==(const wf256_t &, const uint16_t &);
		friend bool operator==(const wf256_t &, const int32_t &);
		friend bool operator==(const wf256_t &, const uint32_t &);
		friend bool operator==(const wf256_t &, const int64_t &);
		friend bool operator==(const wf256_t &, const uint64_t &);
		friend bool operator==(const wf256_t &, const float &);
		friend bool operator==(const wf256_t &, const double &);
		friend bool operator==(const wf256_t &, const long double &);
		friend bool operator==(const wf256_t &, const wf256_t &);
		friend bool operator==(const wf256_t &, const wf512_t &);

		friend bool operator==(const char &, const wf256_t &);
		friend bool operator==(const signed char &, const wf256_t &);
		friend bool operator==(const unsigned char &, const wf256_t &);
		friend bool operator==(const int16_t &, const wf256_t &);
		friend bool operator==(const uint16_t &, const wf256_t &);
		friend bool operator==(const int32_t &, const wf256_t &);
		friend bool operator==(const uint32_t &, const wf256_t &);
		friend bool operator==(const int64_t &, const wf256_t &);
		friend bool operator==(const uint64_t &, const wf256_t &);
		friend bool operator==(const float &, const wf256_t &);
		friend bool operator==(const double &, const wf256_t &);
		friend bool operator==(const long double &, const wf256_t &);
		friend bool operator==(const wf512_t &, const wf256_t &);

		friend bool operator!=(const wf256_t &, const char &);
		friend bool operator!=(const wf256_t &, const signed char &);
		friend bool operator!=(const wf256_t &, const unsigned char &);
		friend bool operator!=(const wf256_t &, const int16_t &);
		friend bool operator!=(const wf256_t &, const uint16_t &);
		friend bool operator!=(const wf256_t &, const int32_t &);
		friend bool operator!=(const wf256_t &, const uint32_t &);
		friend bool operator!=(const wf256_t &, const int64_t &);
		friend bool operator!=(const wf256_t &, const uint64_t &);
		friend bool operator!=(const wf256_t &, const float &);
		friend bool operator!=(const wf256_t &, const double &);
		friend bool operator!=(const wf256_t &, const long double &);
		friend bool operator!=(const wf256_t &, const wf256_t &);
		friend bool operator!=(const wf256_t &, const wf512_t &);

		friend bool operator!=(const char &, const wf256_t &);
		friend bool operator!=(const signed char &, const wf256_t &);
		friend bool operator!=(const unsigned char &, const wf256_t &);
		friend bool operator!=(const int16_t &, const wf256_t &);
		friend bool operator!=(const uint16_t &, const wf256_t &);
		friend bool operator!=(const int32_t &, const wf256_t &);
		friend bool operator!=(const uint32_t &, const wf256_t &);
		friend bool operator!=(const int64_t &, const wf256_t &);
		friend bool operator!=(const uint64_t &, const wf256_t &);
		friend bool operator!=(const float &, const wf256_t &);
		friend bool operator!=(const double &, const wf256_t &);
		friend bool operator!=(const long double &, const wf256_t &);
		friend bool operator!=(const wf512_t &, const wf256_t &);



		/* unary + and - */
		wf256_t operator+ () const;
		wf256_t operator- () const;

		/* square root */
		friend wf256_t sqrt(const wf256_t &);

		/* fma */
		friend wf256_t fma(const wf256_t &, const wf256_t &, const wf256_t &);
};

class wf512_t {
	widefloat_float512_t value;//value

	/*friendship between widefloat classes for constructors and assignments*/
	friend class wf256_t;
	public:
		//constructors
		  wf512_t();
		  wf512_t(const char &);
		  wf512_t(const signed char &);
		  wf512_t(const unsigned char &);
		  wf512_t(const int16_t &);
		  wf512_t(const uint16_t &);
		  wf512_t(const int32_t &);
		  wf512_t(const uint32_t &);
		  wf512_t(const int64_t &);
		  wf512_t(const uint64_t &);
		  wf512_t(const float &);
		  wf512_t(const double &);
		  wf512_t(const long double &);
		  wf512_t(const wf256_t &);


		/*Casts : only towards C++ types*/

		 operator char() const ;
		 operator signed char() const ;
		 operator unsigned char() const ;
		 operator int16_t() const ;
		 operator uint16_t() const ;
		 operator int32_t() const ;
		 operator uint32_t() const ;
		 operator int64_t() const ;
		 operator uint64_t() const ;
		 operator float() const ;
		 operator double() const ;
		 operator long double() const ;

		/*arithmetic operators as friend functions*/

		friend wf512_t operator+(const wf512_t &, const char &);
		friend wf512_t operator+(const wf512_t &, const signed char &);
		friend wf512_t operator+(const wf512_t &, const unsigned char &);
		friend wf512_t operator+(const wf512_t &, const int16_t &);
		friend wf512_t operator+(const wf512_t &, const uint16_t &);
		friend wf512_t operator+(const wf512_t &, const int32_t &);
		friend wf512_t operator+(const wf512_t &, const uint32_t &);
		friend wf512_t operator+(const wf512_t &, const int64_t &);
		friend wf512_t operator+(const wf512_t &, const uint64_t &);
		friend wf512_t operator+(const wf512_t &, const float &);
		friend wf512_t operator+(const wf512_t &, const double &);
		friend wf512_t operator+(const wf512_t &, const long double &);
		friend wf512_t operator+(const wf512_t &, const wf256_t &);
		friend wf512_t operator+(const wf512_t &, const wf512_t &);

		friend wf512_t operator+(const char &, const wf512_t &);
		friend wf512_t operator+(const signed char &, const wf512_t &);
		friend wf512_t operator+(const unsigned char &, const wf512_t &);
		friend wf512_t operator+(const int16_t &, const wf512_t &);
		friend wf512_t operator+(const uint16_t &, const wf512_t &);
		friend wf512_t operator+(const int32_t &, const wf512_t &);
		friend wf512_t operator+(const uint32_t &, const wf512_t &);
		friend wf512_t operator+(const int64_t &, const wf512_t &);
		friend wf512_t operator+(const uint64_t &, const wf512_t &);
		friend wf512_t operator+(const float &, const wf512_t &);
		friend wf512_t operator+(const double &, const wf512_t &);
		friend wf512_t operator+(const long double &, const wf512_t &);
		friend wf512_t operator+(const wf256_t &, const wf512_t &);

		friend wf512_t operator-(const wf512_t &, const char &);
		friend wf512_t operator-(const wf512_t &, const signed char &);
		friend wf512_t operator-(const wf512_t &, const unsigned char &);
		friend wf512_t operator-(const wf512_t &, const int16_t &);
		friend wf512_t operator-(const wf512_t &, const uint16_t &);
		friend wf512_t operator-(const wf512_t &, const int32_t &);
		friend wf512_t operator-(const wf512_t &, const uint32_t &);
		friend wf512_t operator-(const wf512_t &, const int64_t &);
		friend wf512_t operator-(const wf512_t &, const uint64_t &);
		friend wf512_t operator-(const wf512_t &, const float &);
		friend wf512_t operator-(const wf512_t &, const double &);
		friend wf512_t operator-(const wf512_t &, const long double &);
		friend wf512_t operator-(const wf512_t &, const wf256_t &);
		friend wf512_t operator-(const wf512_t &, const wf512_t &);

		friend wf512_t operator-(const char &, const wf512_t &);
		friend wf512_t operator-(const signed char &, const wf512_t &);
		friend wf512_t operator-(const unsigned char &, const wf512_t &);
		friend wf512_t operator-(const int16_t &, const wf512_t &);
		friend wf512_t operator-(const uint16_t &, const wf512_t &);
		friend wf512_t operator-(const int32_t &, const wf512_t &);
		friend wf512_t operator-(const uint32_t &, const wf512_t &);
		friend wf512_t operator-(const int64_t &, const wf512_t &);
		friend wf512_t operator-(const uint64_t &, const wf512_t &);
		friend wf512_t operator-(const float &, const wf512_t &);
		friend wf512_t operator-(const double &, const wf512_t &);
		friend wf512_t operator-(const long double &, const wf512_t &);
		friend wf512_t operator-(const wf256_t &, const wf512_t &);

		friend wf512_t operator*(const wf512_t &, const char &);
		friend wf512_t operator*(const wf512_t &, const signed char &);
		friend wf512_t operator*(const wf512_t &, const unsigned char &);
		friend wf512_t operator*(const wf512_t &, const int16_t &);
		friend wf512_t operator*(const wf512_t &, const uint16_t &);
		friend wf512_t operator*(const wf512_t &, const int32_t &);
		friend wf512_t operator*(const wf512_t &, const uint32_t &);
		friend wf512_t operator*(const wf512_t &, const int64_t &);
		friend wf512_t operator*(const wf512_t &, const uint64_t &);
		friend wf512_t operator*(const wf512_t &, const float &);
		friend wf512_t operator*(const wf512_t &, const double &);
		friend wf512_t operator*(const wf512_t &, const long double &);
		friend wf512_t operator*(const wf512_t &, const wf256_t &);
		friend wf512_t operator*(const wf512_t &, const wf512_t &);

		friend wf512_t operator*(const char &, const wf512_t &);
		friend wf512_t operator*(const signed char &, const wf512_t &);
		friend wf512_t operator*(const unsigned char &, const wf512_t &);
		friend wf512_t operator*(const int16_t &, const wf512_t &);
		friend wf512_t operator*(const uint16_t &, const wf512_t &);
		friend wf512_t operator*(const int32_t &, const wf512_t &);
		friend wf512_t operator*(const uint32_t &, const wf512_t &);
		friend wf512_t operator*(const int64_t &, const wf512_t &);
		friend wf512_t operator*(const uint64_t &, const wf512_t &);
		friend wf512_t operator*(const float &, const wf512_t &);
		friend wf512_t operator*(const double &, const wf512_t &);
		friend wf512_t operator*(const long double &, const wf512_t &);
		friend wf512_t operator*(const wf256_t &, const wf512_t &);

		friend wf512_t operator/(const wf512_t &, const char &);
		friend wf512_t operator/(const wf512_t &, const signed char &);
		friend wf512_t operator/(const wf512_t &, const unsigned char &);
		friend wf512_t operator/(const wf512_t &, const int16_t &);
		friend wf512_t operator/(const wf512_t &, const uint16_t &);
		friend wf512_t operator/(const wf512_t &, const int32_t &);
		friend wf512_t operator/(const wf512_t &, const uint32_t &);
		friend wf512_t operator/(const wf512_t &, const int64_t &);
		friend wf512_t operator/(const wf512_t &, const uint64_t &);
		friend wf512_t operator/(const wf512_t &, const float &);
		friend wf512_t operator/(const wf512_t &, const double &);
		friend wf512_t operator/(const wf512_t &, const long double &);
		friend wf512_t operator/(const wf512_t &, const wf256_t &);
		friend wf512_t operator/(const wf512_t &, const wf512_t &);

		friend wf512_t operator/(const char &, const wf512_t &);
		friend wf512_t operator/(const signed char &, const wf512_t &);
		friend wf512_t operator/(const unsigned char &, const wf512_t &);
		friend wf512_t operator/(const int16_t &, const wf512_t &);
		friend wf512_t operator/(const uint16_t &, const wf512_t &);
		friend wf512_t operator/(const int32_t &, const wf512_t &);
		friend wf512_t operator/(const uint32_t &, const wf512_t &);
		friend wf512_t operator/(const int64_t &, const wf512_t &);
		friend wf512_t operator/(const uint64_t &, const wf512_t &);
		friend wf512_t operator/(const float &, const wf512_t &);
		friend wf512_t operator/(const double &, const wf512_t &);
		friend wf512_t operator/(const long double &, const wf512_t &);
		friend wf512_t operator/(const wf256_t &, const wf512_t &);


		/*assignments (as members)*/
		 wf512_t operator= (const char &);
		 wf512_t operator= (const signed char &);
		 wf512_t operator= (const unsigned char &);
		 wf512_t operator= (const int16_t &);
		 wf512_t operator= (const uint16_t &);
		 wf512_t operator= (const int32_t &);
		 wf512_t operator= (const uint32_t &);
		 wf512_t operator= (const int64_t &);
		 wf512_t operator= (const uint64_t &);
		 wf512_t operator= (const float &);
		 wf512_t operator= (const double &);
		 wf512_t operator= (const long double &);
		 wf512_t operator= (const wf256_t &);


		/*extended assignments as friend functions*/
		friend wf512_t operator+=(wf512_t &, const char &);
		friend wf512_t operator+=(wf512_t &, const signed char &);
		friend wf512_t operator+=(wf512_t &, const unsigned char &);
		friend wf512_t operator+=(wf512_t &, const int16_t &);
		friend wf512_t operator+=(wf512_t &, const uint16_t &);
		friend wf512_t operator+=(wf512_t &, const int32_t &);
		friend wf512_t operator+=(wf512_t &, const uint32_t &);
		friend wf512_t operator+=(wf512_t &, const int64_t &);
		friend wf512_t operator+=(wf512_t &, const uint64_t &);
		friend wf512_t operator+=(wf512_t &, const float &);
		friend wf512_t operator+=(wf512_t &, const double &);
		friend wf512_t operator+=(wf512_t &, const long double &);
		friend wf512_t operator+=(wf512_t &, const wf256_t &);
		friend wf512_t operator+=(wf512_t &, const wf512_t &);

		friend char operator+=(char &, const wf512_t &);
		friend signed char operator+=(signed char &, const wf512_t &);
		friend unsigned char operator+=(unsigned char &, const wf512_t &);
		friend int16_t operator+=(int16_t &, const wf512_t &);
		friend uint16_t operator+=(uint16_t &, const wf512_t &);
		friend int32_t operator+=(int32_t &, const wf512_t &);
		friend uint32_t operator+=(uint32_t &, const wf512_t &);
		friend int64_t operator+=(int64_t &, const wf512_t &);
		friend uint64_t operator+=(uint64_t &, const wf512_t &);
		friend float operator+=(float &, const wf512_t &);
		friend double operator+=(double &, const wf512_t &);
		friend long double operator+=(long double &, const wf512_t &);
		friend wf256_t operator+=(wf256_t &, const wf512_t &);

		friend wf512_t operator-=(wf512_t &, const char &);
		friend wf512_t operator-=(wf512_t &, const signed char &);
		friend wf512_t operator-=(wf512_t &, const unsigned char &);
		friend wf512_t operator-=(wf512_t &, const int16_t &);
		friend wf512_t operator-=(wf512_t &, const uint16_t &);
		friend wf512_t operator-=(wf512_t &, const int32_t &);
		friend wf512_t operator-=(wf512_t &, const uint32_t &);
		friend wf512_t operator-=(wf512_t &, const int64_t &);
		friend wf512_t operator-=(wf512_t &, const uint64_t &);
		friend wf512_t operator-=(wf512_t &, const float &);
		friend wf512_t operator-=(wf512_t &, const double &);
		friend wf512_t operator-=(wf512_t &, const long double &);
		friend wf512_t operator-=(wf512_t &, const wf256_t &);
		friend wf512_t operator-=(wf512_t &, const wf512_t &);

		friend char operator-=(char &, const wf512_t &);
		friend signed char operator-=(signed char &, const wf512_t &);
		friend unsigned char operator-=(unsigned char &, const wf512_t &);
		friend int16_t operator-=(int16_t &, const wf512_t &);
		friend uint16_t operator-=(uint16_t &, const wf512_t &);
		friend int32_t operator-=(int32_t &, const wf512_t &);
		friend uint32_t operator-=(uint32_t &, const wf512_t &);
		friend int64_t operator-=(int64_t &, const wf512_t &);
		friend uint64_t operator-=(uint64_t &, const wf512_t &);
		friend float operator-=(float &, const wf512_t &);
		friend double operator-=(double &, const wf512_t &);
		friend long double operator-=(long double &, const wf512_t &);
		friend wf256_t operator-=(wf256_t &, const wf512_t &);

		friend wf512_t operator*=(wf512_t &, const char &);
		friend wf512_t operator*=(wf512_t &, const signed char &);
		friend wf512_t operator*=(wf512_t &, const unsigned char &);
		friend wf512_t operator*=(wf512_t &, const int16_t &);
		friend wf512_t operator*=(wf512_t &, const uint16_t &);
		friend wf512_t operator*=(wf512_t &, const int32_t &);
		friend wf512_t operator*=(wf512_t &, const uint32_t &);
		friend wf512_t operator*=(wf512_t &, const int64_t &);
		friend wf512_t operator*=(wf512_t &, const uint64_t &);
		friend wf512_t operator*=(wf512_t &, const float &);
		friend wf512_t operator*=(wf512_t &, const double &);
		friend wf512_t operator*=(wf512_t &, const long double &);
		friend wf512_t operator*=(wf512_t &, const wf256_t &);
		friend wf512_t operator*=(wf512_t &, const wf512_t &);

		friend char operator*=(char &, const wf512_t &);
		friend signed char operator*=(signed char &, const wf512_t &);
		friend unsigned char operator*=(unsigned char &, const wf512_t &);
		friend int16_t operator*=(int16_t &, const wf512_t &);
		friend uint16_t operator*=(uint16_t &, const wf512_t &);
		friend int32_t operator*=(int32_t &, const wf512_t &);
		friend uint32_t operator*=(uint32_t &, const wf512_t &);
		friend int64_t operator*=(int64_t &, const wf512_t &);
		friend uint64_t operator*=(uint64_t &, const wf512_t &);
		friend float operator*=(float &, const wf512_t &);
		friend double operator*=(double &, const wf512_t &);
		friend long double operator*=(long double &, const wf512_t &);
		friend wf256_t operator*=(wf256_t &, const wf512_t &);

		friend wf512_t operator/=(wf512_t &, const char &);
		friend wf512_t operator/=(wf512_t &, const signed char &);
		friend wf512_t operator/=(wf512_t &, const unsigned char &);
		friend wf512_t operator/=(wf512_t &, const int16_t &);
		friend wf512_t operator/=(wf512_t &, const uint16_t &);
		friend wf512_t operator/=(wf512_t &, const int32_t &);
		friend wf512_t operator/=(wf512_t &, const uint32_t &);
		friend wf512_t operator/=(wf512_t &, const int64_t &);
		friend wf512_t operator/=(wf512_t &, const uint64_t &);
		friend wf512_t operator/=(wf512_t &, const float &);
		friend wf512_t operator/=(wf512_t &, const double &);
		friend wf512_t operator/=(wf512_t &, const long double &);
		friend wf512_t operator/=(wf512_t &, const wf256_t &);
		friend wf512_t operator/=(wf512_t &, const wf512_t &);

		friend char operator/=(char &, const wf512_t &);
		friend signed char operator/=(signed char &, const wf512_t &);
		friend unsigned char operator/=(unsigned char &, const wf512_t &);
		friend int16_t operator/=(int16_t &, const wf512_t &);
		friend uint16_t operator/=(uint16_t &, const wf512_t &);
		friend int32_t operator/=(int32_t &, const wf512_t &);
		friend uint32_t operator/=(uint32_t &, const wf512_t &);
		friend int64_t operator/=(int64_t &, const wf512_t &);
		friend uint64_t operator/=(uint64_t &, const wf512_t &);
		friend float operator/=(float &, const wf512_t &);
		friend double operator/=(double &, const wf512_t &);
		friend long double operator/=(long double &, const wf512_t &);
		friend wf256_t operator/=(wf256_t &, const wf512_t &);



		/*comparisons*/
		friend bool operator<(const wf512_t &, const char &);
		friend bool operator<(const wf512_t &, const signed char &);
		friend bool operator<(const wf512_t &, const unsigned char &);
		friend bool operator<(const wf512_t &, const int16_t &);
		friend bool operator<(const wf512_t &, const uint16_t &);
		friend bool operator<(const wf512_t &, const int32_t &);
		friend bool operator<(const wf512_t &, const uint32_t &);
		friend bool operator<(const wf512_t &, const int64_t &);
		friend bool operator<(const wf512_t &, const uint64_t &);
		friend bool operator<(const wf512_t &, const float &);
		friend bool operator<(const wf512_t &, const double &);
		friend bool operator<(const wf512_t &, const long double &);
		friend bool operator<(const wf512_t &, const wf256_t &);
		friend bool operator<(const wf512_t &, const wf512_t &);

		friend bool operator<(const char &, const wf512_t &);
		friend bool operator<(const signed char &, const wf512_t &);
		friend bool operator<(const unsigned char &, const wf512_t &);
		friend bool operator<(const int16_t &, const wf512_t &);
		friend bool operator<(const uint16_t &, const wf512_t &);
		friend bool operator<(const int32_t &, const wf512_t &);
		friend bool operator<(const uint32_t &, const wf512_t &);
		friend bool operator<(const int64_t &, const wf512_t &);
		friend bool operator<(const uint64_t &, const wf512_t &);
		friend bool operator<(const float &, const wf512_t &);
		friend bool operator<(const double &, const wf512_t &);
		friend bool operator<(const long double &, const wf512_t &);
		friend bool operator<(const wf256_t &, const wf512_t &);

		friend bool operator>(const wf512_t &, const char &);
		friend bool operator>(const wf512_t &, const signed char &);
		friend bool operator>(const wf512_t &, const unsigned char &);
		friend bool operator>(const wf512_t &, const int16_t &);
		friend bool operator>(const wf512_t &, const uint16_t &);
		friend bool operator>(const wf512_t &, const int32_t &);
		friend bool operator>(const wf512_t &, const uint32_t &);
		friend bool operator>(const wf512_t &, const int64_t &);
		friend bool operator>(const wf512_t &, const uint64_t &);
		friend bool operator>(const wf512_t &, const float &);
		friend bool operator>(const wf512_t &, const double &);
		friend bool operator>(const wf512_t &, const long double &);
		friend bool operator>(const wf512_t &, const wf256_t &);
		friend bool operator>(const wf512_t &, const wf512_t &);

		friend bool operator>(const char &, const wf512_t &);
		friend bool operator>(const signed char &, const wf512_t &);
		friend bool operator>(const unsigned char &, const wf512_t &);
		friend bool operator>(const int16_t &, const wf512_t &);
		friend bool operator>(const uint16_t &, const wf512_t &);
		friend bool operator>(const int32_t &, const wf512_t &);
		friend bool operator>(const uint32_t &, const wf512_t &);
		friend bool operator>(const int64_t &, const wf512_t &);
		friend bool operator>(const uint64_t &, const wf512_t &);
		friend bool operator>(const float &, const wf512_t &);
		friend bool operator>(const double &, const wf512_t &);
		friend bool operator>(const long double &, const wf512_t &);
		friend bool operator>(const wf256_t &, const wf512_t &);

		friend bool operator<=(const wf512_t &, const char &);
		friend bool operator<=(const wf512_t &, const signed char &);
		friend bool operator<=(const wf512_t &, const unsigned char &);
		friend bool operator<=(const wf512_t &, const int16_t &);
		friend bool operator<=(const wf512_t &, const uint16_t &);
		friend bool operator<=(const wf512_t &, const int32_t &);
		friend bool operator<=(const wf512_t &, const uint32_t &);
		friend bool operator<=(const wf512_t &, const int64_t &);
		friend bool operator<=(const wf512_t &, const uint64_t &);
		friend bool operator<=(const wf512_t &, const float &);
		friend bool operator<=(const wf512_t &, const double &);
		friend bool operator<=(const wf512_t &, const long double &);
		friend bool operator<=(const wf512_t &, const wf256_t &);
		friend bool operator<=(const wf512_t &, const wf512_t &);

		friend bool operator<=(const char &, const wf512_t &);
		friend bool operator<=(const signed char &, const wf512_t &);
		friend bool operator<=(const unsigned char &, const wf512_t &);
		friend bool operator<=(const int16_t &, const wf512_t &);
		friend bool operator<=(const uint16_t &, const wf512_t &);
		friend bool operator<=(const int32_t &, const wf512_t &);
		friend bool operator<=(const uint32_t &, const wf512_t &);
		friend bool operator<=(const int64_t &, const wf512_t &);
		friend bool operator<=(const uint64_t &, const wf512_t &);
		friend bool operator<=(const float &, const wf512_t &);
		friend bool operator<=(const double &, const wf512_t &);
		friend bool operator<=(const long double &, const wf512_t &);
		friend bool operator<=(const wf256_t &, const wf512_t &);

		friend bool operator>=(const wf512_t &, const char &);
		friend bool operator>=(const wf512_t &, const signed char &);
		friend bool operator>=(const wf512_t &, const unsigned char &);
		friend bool operator>=(const wf512_t &, const int16_t &);
		friend bool operator>=(const wf512_t &, const uint16_t &);
		friend bool operator>=(const wf512_t &, const int32_t &);
		friend bool operator>=(const wf512_t &, const uint32_t &);
		friend bool operator>=(const wf512_t &, const int64_t &);
		friend bool operator>=(const wf512_t &, const uint64_t &);
		friend bool operator>=(const wf512_t &, const float &);
		friend bool operator>=(const wf512_t &, const double &);
		friend bool operator>=(const wf512_t &, const long double &);
		friend bool operator>=(const wf512_t &, const wf256_t &);
		friend bool operator>=(const wf512_t &, const wf512_t &);

		friend bool operator>=(const char &, const wf512_t &);
		friend bool operator>=(const signed char &, const wf512_t &);
		friend bool operator>=(const unsigned char &, const wf512_t &);
		friend bool operator>=(const int16_t &, const wf512_t &);
		friend bool operator>=(const uint16_t &, const wf512_t &);
		friend bool operator>=(const int32_t &, const wf512_t &);
		friend bool operator>=(const uint32_t &, const wf512_t &);
		friend bool operator>=(const int64_t &, const wf512_t &);
		friend bool operator>=(const uint64_t &, const wf512_t &);
		friend bool operator>=(const float &, const wf512_t &);
		friend bool operator>=(const double &, const wf512_t &);
		friend bool operator>=(const long double &, const wf512_t &);
		friend bool operator>=(const wf256_t &, const wf512_t &);

		friend bool operator==(const wf512_t &, const char &);
		friend bool operator==(const wf512_t &, const signed char &);
		friend bool operator==(const wf512_t &, const unsigned char &);
		friend bool operator==(const wf512_t &, const int16_t &);
		friend bool operator==(const wf512_t &, const uint16_t &);
		friend bool operator==(const wf512_t &, const int32_t &);
		friend bool operator==(const wf512_t &, const uint32_t &);
		friend bool operator==(const wf512_t &, const int64_t &);
		friend bool operator==(const wf512_t &, const uint64_t &);
		friend bool operator==(const wf512_t &, const float &);
		friend bool operator==(const wf512_t &, const double &);
		friend bool operator==(const wf512_t &, const long double &);
		friend bool operator==(const wf512_t &, const wf256_t &);
		friend bool operator==(const wf512_t &, const wf512_t &);

		friend bool operator==(const char &, const wf512_t &);
		friend bool operator==(const signed char &, const wf512_t &);
		friend bool operator==(const unsigned char &, const wf512_t &);
		friend bool operator==(const int16_t &, const wf512_t &);
		friend bool operator==(const uint16_t &, const wf512_t &);
		friend bool operator==(const int32_t &, const wf512_t &);
		friend bool operator==(const uint32_t &, const wf512_t &);
		friend bool operator==(const int64_t &, const wf512_t &);
		friend bool operator==(const uint64_t &, const wf512_t &);
		friend bool operator==(const float &, const wf512_t &);
		friend bool operator==(const double &, const wf512_t &);
		friend bool operator==(const long double &, const wf512_t &);
		friend bool operator==(const wf256_t &, const wf512_t &);

		friend bool operator!=(const wf512_t &, const char &);
		friend bool operator!=(const wf512_t &, const signed char &);
		friend bool operator!=(const wf512_t &, const unsigned char &);
		friend bool operator!=(const wf512_t &, const int16_t &);
		friend bool operator!=(const wf512_t &, const uint16_t &);
		friend bool operator!=(const wf512_t &, const int32_t &);
		friend bool operator!=(const wf512_t &, const uint32_t &);
		friend bool operator!=(const wf512_t &, const int64_t &);
		friend bool operator!=(const wf512_t &, const uint64_t &);
		friend bool operator!=(const wf512_t &, const float &);
		friend bool operator!=(const wf512_t &, const double &);
		friend bool operator!=(const wf512_t &, const long double &);
		friend bool operator!=(const wf512_t &, const wf256_t &);
		friend bool operator!=(const wf512_t &, const wf512_t &);

		friend bool operator!=(const char &, const wf512_t &);
		friend bool operator!=(const signed char &, const wf512_t &);
		friend bool operator!=(const unsigned char &, const wf512_t &);
		friend bool operator!=(const int16_t &, const wf512_t &);
		friend bool operator!=(const uint16_t &, const wf512_t &);
		friend bool operator!=(const int32_t &, const wf512_t &);
		friend bool operator!=(const uint32_t &, const wf512_t &);
		friend bool operator!=(const int64_t &, const wf512_t &);
		friend bool operator!=(const uint64_t &, const wf512_t &);
		friend bool operator!=(const float &, const wf512_t &);
		friend bool operator!=(const double &, const wf512_t &);
		friend bool operator!=(const long double &, const wf512_t &);
		friend bool operator!=(const wf256_t &, const wf512_t &);



		/* unary + and - */
		wf512_t operator+ () const;
		wf512_t operator- () const;

		/* square root */
		friend wf512_t sqrt(const wf512_t &);

		/* fma */
		friend wf512_t fma(const wf512_t &, const wf512_t &, const wf512_t &);
};

#endif