add_executable(app
    App.cpp
)

target_link_libraries(app PUBLIC curve)

find_package(OpenMP)
if(OpenMP_CXX_FOUND)
    target_link_libraries(app PUBLIC OpenMP::OpenMP_CXX)
endif()

