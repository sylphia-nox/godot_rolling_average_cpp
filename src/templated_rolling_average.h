#pragma once

#include <concepts>
#include "godot_cpp/classes/ref_counted.hpp"
#include "godot_cpp/classes/wrapped.hpp"
#include "godot_cpp/variant/variant.hpp"

using namespace godot;

template <typename TArray, typename TValue>
concept AllowedTypePairs = (std::same_as<TArray, PackedVector2Array> && std::same_as<TValue, Vector2>) ||
                  (std::same_as<TArray, PackedVector3Array> && std::same_as<TValue, Vector3>) ||
                  (std::same_as<TArray, PackedVector4Array> && std::same_as<TValue, Vector4>) ||
                  (std::same_as<TArray, PackedFloat32Array> && std::same_as<TValue, float>) ||
                  (std::same_as<TArray, PackedFloat64Array> && std::same_as<TValue, double>);




template <typename TArray, typename TValue>
requires AllowedTypePairs<TArray, TValue>
class RollingAverage : public RefCounted {
    GDCLASS(RollingAverage, RefCounted)

	protected:
		static void _bind_methods();

	private:
		uint8_t index = 0;
		TArray stored_values;
		uint8_t window_size;
		Vector3 sum = Vector3(0, 0, 0);

		void check_length(const TArray &p_array, uint8_t p_window_size) {
			if (p_array.size() != p_window_size) {
				throw std::invalid_argument("Cannot populate rolling average with array of different size");
			}
}

	public:
		RollingAverage(int window_size) {
			stored_values.resize(window_size);
			this->window_size = window_size;
		}
		~RollingAverage() override = default;

		void populate(const TArray &p_values) {
			try{
				check_length(p_values, window_size);
			} catch (const std::invalid_argument &e) {
				throw;
			}
			stored_values = p_values;
			for (int i = 0; i < window_size; i++) {
				sum += stored_values[i];
			}
		}

		TValue update(const TValue &p_new_value) {
			sum -= stored_values[index];
			sum += p_new_value;
			index = (index + 1) % window_size;
			stored_values[index] = p_new_value;
		}

		TValue get_value() const {
			return sum / window_size;
		}



};