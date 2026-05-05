#pragma once

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class Float32RollingAverage : public RefCounted {
    GDCLASS(Float32RollingAverage, RefCounted)

	protected:
		static void _bind_methods();

	private:
		uint8_t index = 0;
		PackedFloat32Array stored_values;
		uint8_t window_size;
		float sum = 0.0;

	public:
		Float32RollingAverage() = default;
		~Float32RollingAverage() override = default;

		void set_window_size(uint8_t p_window_size) {
			stored_values.resize(p_window_size);
			this->window_size = p_window_size;
		}

		void populate(const PackedFloat32Array &p_values) {
			stored_values = p_values;
			for (int i = 0; i < window_size; i++) {
				sum += stored_values[i];
			}
		}

		float update(const float &p_new_value) {
			sum -= stored_values[index];
			sum += p_new_value;
            stored_values[index] = p_new_value;
			index = (index + 1) % window_size;
			return sum / window_size;
		}

		float get_value() const {
			return sum / window_size;
		}



};