add_library(curve SHARED
  src/Vector.cpp
  src/Helix.cpp
  src/Ellipse.cpp
  src/Circle.cpp
)

target_include_directories(curve PUBLIC include)

add_executable(curvetest
  test/TestMain.cpp
  test/TestVector.cpp
  test/TestCircle.cpp
  test/TestEllipse.cpp
  test/TestHelix.cpp
)

target_link_libraries(curvetest
  gtest
  curve
)

