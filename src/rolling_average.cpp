#include "vector2_rolling_average.h"
#include "vector3_rolling_average.h"
#include "vector4_rolling_average.h"
#include "float32_rolling_average.h"
#include "float64_rolling_average.h"




void Vector2RollingAverage::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_window_size"), &Vector2RollingAverage::set_window_size);
	ClassDB::bind_method(D_METHOD("populate"), &Vector2RollingAverage::populate);
	ClassDB::bind_method(D_METHOD("get_value"), &Vector2RollingAverage::get_value);
	ClassDB::bind_method(D_METHOD("update"), &Vector2RollingAverage::update);
};
void Vector3RollingAverage::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_window_size"), &Vector3RollingAverage::set_window_size);
	ClassDB::bind_method(D_METHOD("populate"), &Vector3RollingAverage::populate);
	ClassDB::bind_method(D_METHOD("get_value"), &Vector3RollingAverage::get_value);
	ClassDB::bind_method(D_METHOD("update"), &Vector3RollingAverage::update);
};
void Vector4RollingAverage::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_window_size"), &Vector4RollingAverage::set_window_size);
	ClassDB::bind_method(D_METHOD("populate"), &Vector4RollingAverage::populate);
	ClassDB::bind_method(D_METHOD("get_value"), &Vector4RollingAverage::get_value);
	ClassDB::bind_method(D_METHOD("update"), &Vector4RollingAverage::update);
};
void Float32RollingAverage::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_window_size"), &Float32RollingAverage::set_window_size);
	ClassDB::bind_method(D_METHOD("populate"), &Float32RollingAverage::populate);
	ClassDB::bind_method(D_METHOD("get_value"), &Float32RollingAverage::get_value);
	ClassDB::bind_method(D_METHOD("update"), &Float32RollingAverage::update);
};
void Float64RollingAverage::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_window_size"), &Float64RollingAverage::set_window_size);
	ClassDB::bind_method(D_METHOD("populate"), &Float64RollingAverage::populate);
	ClassDB::bind_method(D_METHOD("get_value"), &Float64RollingAverage::get_value);
	ClassDB::bind_method(D_METHOD("update"), &Float64RollingAverage::update);
};
