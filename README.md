# DOAN_CTDLGT

A simple project made by me.

# About
- Trong chương trình, Robot được đặc tả bộ não - gồm 4 chế độ di chuyển: Normal, Medium, Hard, User
    - Chế độ normal: Robot sẽ tránh các va chạm và sẽ tự động di chuyển tùy ý.
    - Chế độ medium: Robot sẽ được khởi động thông minh hơn, biết chọn lọc những điểm đã đi qua và tránh đi lại để giảm thiểu thời gian cũng như nguồn điện cấp phát.
	  - Chế độ hard: Robot được trang bị 1 con AI cơ bản, nhằm giúp tối ưu việc di chuyển cũng như tránh lặp lại các bước đi. Tuy nhiên, do kiến thức hạn hẹp nên AI chỉ được build ở chế độ cơ bản trên nền BFS + A*.
	
    - Chế độ USER: Ở chế độ này, người dùng sẽ tự do điều khiển robot nhưng robot cũng được trang bị 1 con AI nhằm quản lý cách di chuyển của người dùng, hòng tránh việc người dùng lỡ may di chuyển khiến robot va vào tuờng, robot sẽ tự động điều hướng.
