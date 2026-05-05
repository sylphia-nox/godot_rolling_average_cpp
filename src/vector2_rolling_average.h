#pragma once

#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

class Vector2RollingAverage : public RefCounted {
    GDCLASS(Vector2RollingAverage, RefCounted)

	protected:
		static void _bind_methods();

	private:
		uint8_t index = 0;
		PackedVector2Array stored_values;
		uint8_t window_size;
		Vector2 sum = Vector2(0, 0);

	public:
		Vector2RollingAverage() = default;
		~Vector2RollingAverage() override = default;

        void set_window_size(uint8_t p_window_size) {
			stored_values.resize(p_window_size);
			this->window_size = p_window_size;
		}

		void populate(const PackedVector2Array &p_values) {
			stored_values = p_values;
			for (int i = 0; i < window_size; i++) {
				sum += stored_values[i];
			}
		}

		Vector2 update(const Vector2 &p_new_value) {
			sum -= stored_values[index];
			sum += p_new_value;
            stored_values[index] = p_new_value;
			index = (index + 1) % window_size;
			return sum / window_size;
		}

		Vector2 get_value() const {
			return sum / window_size;
		}



};