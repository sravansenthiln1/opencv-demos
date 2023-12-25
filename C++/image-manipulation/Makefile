CXXFLAGS+=-lopencv_core \
		  -lopencv_imgproc \
		  -lopencv_videoio \
		  -lopencv_imgcodecs \
		  -lopencv_highgui \
		  -lopencv_calib3d
		  
CXXFLAGS+=-std=c++11 \
		  -std=gnu++11 \
		  -std=c++11 \
		  -lstdc++ \
		  -lm

INCLUDE_CV2:=/usr/include/opencv4

SRC:=main.cpp
OUT:=main

default: $(OUT)

$(OUT): $(OBJS)
	$(CC) -Wall -Wextra \
	-I $(INCLUDE_CV2) \
	$(SRC) -o $(OUT) $(CXXFLAGS)

clean:
	rm -rf $(OUT) $(OBJS)
