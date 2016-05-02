extern "C" {
#include "widefloat_float_ext.h"
}


#include "wf_classes.h"



	/* constructors */

wf256_t::wf256_t (){
	widefloat_ext_float256_from_ieee754_binary64(&value, 0.0);
}

wf256_t::wf256_t (const char & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const signed char & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const unsigned char & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const int16_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const uint16_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const int32_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const uint32_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const int64_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const uint64_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);
	widefloat_ext_convert_float64_to_float256(&value, &v2);
}

wf256_t::wf256_t (const float & v){
	widefloat_ext_float256_from_ieee754_binary32(&value, v);
}

wf256_t::wf256_t (const double & v){
	widefloat_ext_float256_from_ieee754_binary64(&value, v);
}

wf256_t::wf256_t (const long double & v){
	widefloat_ext_float256_from_ieee754_binary64(&value, (double)v);
}

wf256_t::wf256_t (const wf512_t & v){
	widefloat_ext_convert_float512_to_float256(&value, &(v.value));
}

wf512_t::wf512_t (){
	widefloat_ext_float512_from_ieee754_binary64(&value, 0.0);
}

wf512_t::wf512_t (const char & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const signed char & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const unsigned char & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const int16_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const uint16_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const int32_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const uint32_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const int64_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_signed_integer(&v2, (int64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const uint64_t & v){
	widefloat_float64_t v2;
	widefloat_ext_convert_float64_from_unsigned_integer(&v2, (uint64_t)v);
	widefloat_ext_convert_float64_to_float512(&value, &v2);
}

wf512_t::wf512_t (const float & v){
	widefloat_ext_float512_from_ieee754_binary32(&value, v);
}

wf512_t::wf512_t (const double & v){
	widefloat_ext_float512_from_ieee754_binary64(&value, v);
}

wf512_t::wf512_t (const long double & v){
	widefloat_ext_float512_from_ieee754_binary64(&value, (double)v);
}

wf512_t::wf512_t (const wf256_t & v){
	widefloat_ext_convert_float256_to_float512(&value, &(v.value));
}

	/* casts */


wf256_t::operator char() const{
	int64_t res;
	widefloat_ext_convert_float256_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (char)res;
}

wf256_t::operator signed char() const{
	int64_t res;
	widefloat_ext_convert_float256_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (signed char)res;
}

wf256_t::operator unsigned char() const{
	uint64_t res;
	widefloat_ext_convert_float256_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (unsigned char)res;
}

wf256_t::operator int16_t() const{
	int64_t res;
	widefloat_ext_convert_float256_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (int16_t)res;
}

wf256_t::operator uint16_t() const{
	uint64_t res;
	widefloat_ext_convert_float256_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (uint16_t)res;
}

wf256_t::operator int32_t() const{
	int64_t res;
	widefloat_ext_convert_float256_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (int32_t)res;
}

wf256_t::operator uint32_t() const{
	uint64_t res;
	widefloat_ext_convert_float256_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (uint32_t)res;
}

wf256_t::operator int64_t() const{
	int64_t res;
	widefloat_ext_convert_float256_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (int64_t)res;
}

wf256_t::operator uint64_t() const{
	uint64_t res;
	widefloat_ext_convert_float256_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (uint64_t)res;
}

wf256_t::operator float() const{
	float res;
	widefloat_ext_float256_to_ieee754_binary32(&res, &value);
	return res;
}

wf256_t::operator double() const{
	double res;
	widefloat_ext_float256_to_ieee754_binary64(&res, &value);
	return res;
}

wf256_t::operator long double() const{
	double res;
	widefloat_ext_float256_to_ieee754_binary64(&res, &value);
	return (long double)res;
}

wf512_t::operator char() const{
	int64_t res;
	widefloat_ext_convert_float512_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (char)res;
}

wf512_t::operator signed char() const{
	int64_t res;
	widefloat_ext_convert_float512_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (signed char)res;
}

wf512_t::operator unsigned char() const{
	uint64_t res;
	widefloat_ext_convert_float512_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (unsigned char)res;
}

wf512_t::operator int16_t() const{
	int64_t res;
	widefloat_ext_convert_float512_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (int16_t)res;
}

wf512_t::operator uint16_t() const{
	uint64_t res;
	widefloat_ext_convert_float512_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (uint16_t)res;
}

wf512_t::operator int32_t() const{
	int64_t res;
	widefloat_ext_convert_float512_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (int32_t)res;
}

wf512_t::operator uint32_t() const{
	uint64_t res;
	widefloat_ext_convert_float512_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (uint32_t)res;
}

wf512_t::operator int64_t() const{
	int64_t res;
	widefloat_ext_convert_float512_to_signed_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (int64_t)res;
}

wf512_t::operator uint64_t() const{
	uint64_t res;
	widefloat_ext_convert_float512_to_unsigned_integer_mode_exact(&res, &value, WIDEFLOAT_ROUNDINGMODE_NEAREST);
	return (uint64_t)res;
}

wf512_t::operator float() const{
	float res;
	widefloat_ext_float512_to_ieee754_binary32(&res, &value);
	return res;
}

wf512_t::operator double() const{
	double res;
	widefloat_ext_float512_to_ieee754_binary64(&res, &value);
	return res;
}

wf512_t::operator long double() const{
	double res;
	widefloat_ext_float512_to_ieee754_binary64(&res, &value);
	return (long double)res;
}


	/* operators : + - * / */

wf256_t operator + (const char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const signed char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const signed char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const unsigned char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const unsigned char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const int16_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const int16_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const uint16_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const uint16_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const int32_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const int32_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const uint32_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const uint32_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const int64_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const int64_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const uint64_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const uint64_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const float &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const float &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const double &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const double &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const long double &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator + (const long double &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf512_t operator + (const wf256_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const wf256_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const signed char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const unsigned char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const int16_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const uint16_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const int32_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const uint32_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const int64_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const uint64_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const float &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const double &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator + (const wf256_t &op1, const long double &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_add_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const signed char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const unsigned char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const int16_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const uint16_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const int32_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const uint32_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const int64_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const uint64_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const float &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const double &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator + (const wf512_t &op1, const long double &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_add_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const signed char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const signed char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const unsigned char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const unsigned char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const int16_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const int16_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const uint16_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const uint16_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const int32_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const int32_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const uint32_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const uint32_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const int64_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const int64_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const uint64_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const uint64_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const float &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const float &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const double &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const double &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const long double &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator - (const long double &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf512_t operator - (const wf256_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const wf256_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const signed char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const unsigned char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const int16_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const uint16_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const int32_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const uint32_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const int64_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const uint64_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const float &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const double &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator - (const wf256_t &op1, const long double &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_sub_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const signed char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const unsigned char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const int16_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const uint16_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const int32_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const uint32_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const int64_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const uint64_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const float &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const double &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator - (const wf512_t &op1, const long double &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_sub_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const signed char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const signed char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const unsigned char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const unsigned char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const int16_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const int16_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const uint16_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const uint16_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const int32_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const int32_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const uint32_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const uint32_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const int64_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const int64_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const uint64_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const uint64_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const float &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const float &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const double &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const double &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const long double &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator * (const long double &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf512_t operator * (const wf256_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const wf256_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const signed char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const unsigned char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const int16_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const uint16_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const int32_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const uint32_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const int64_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const uint64_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const float &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const double &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator * (const wf256_t &op1, const long double &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_mul_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const signed char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const unsigned char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const int16_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const uint16_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const int32_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const uint32_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const int64_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const uint64_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const float &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const double &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator * (const wf512_t &op1, const long double &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_mul_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const signed char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const signed char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const unsigned char &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const unsigned char &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const int16_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const int16_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const uint16_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const uint16_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const int32_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const int32_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const uint32_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const uint32_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const int64_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const int64_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const uint64_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const uint64_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const float &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const float &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const double &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const double &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const long double &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op1;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf512_t operator / (const long double &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op2.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const wf256_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf512_t operator / (const wf256_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op1;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const wf256_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const wf512_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op3.value), &(op2.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const signed char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const unsigned char &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const int16_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const uint16_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const int32_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const uint32_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const int64_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const uint64_t &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const float &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const double &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf256_t operator / (const wf256_t &op1, const long double &op2){
	wf256_t res;
	wf256_t op3 = op2;
	widefloat_ext_div_float256_float256_float256(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const signed char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const unsigned char &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const int16_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const uint16_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const int32_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const uint32_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const int64_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const uint64_t &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const float &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const double &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}

wf512_t operator / (const wf512_t &op1, const long double &op2){
	wf512_t res;
	wf512_t op3 = op2;
	widefloat_ext_div_float512_float512_float512(&(res.value), &(op1.value), &(op3.value));
	return res;
}
