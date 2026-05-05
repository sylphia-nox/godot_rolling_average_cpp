@tool
extends EditorScript

func _run():
	print("hello world")
	
	var vector2_test_avg = Vector2RollingAverage.new()
	vector2_test_avg.set_window_size(10)
	
	vector2_test_avg.update(Vector2(10, 5))
	
	assert (vector2_test_avg.get_value() == Vector2(1.0, 0.5), "Avg was incorrect") 
