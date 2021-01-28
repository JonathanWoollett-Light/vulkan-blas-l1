#include <gtest/gtest.h>
#include "../Example.hpp"

const uint32_t WORKGROUP_SIZE = 1024;

TEST(Boilerplate, ten) {
    uint32_t const size = 10;
    char const shader[] = "../../glsl/plus.spv";
    float* array = new float[size];
    std::fill(array,array+size,1);
    for(uint32_t i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
    ComputeApp app = ComputeApp(
        shader,
        size, // Buffer sizes
        array, // Buffer data
        new uint32_t[3]{ size,1,1 }, // Invocations
        new uint32_t[3]{ WORKGROUP_SIZE,1,1 } // Workgroup sizes
    );
    float* out = static_cast<float*>(Utility::map(app.device,app.bufferMemory));
    for(uint32_t i = 0; i < size; ++i) {
        std::cout << out[i] << ' ';
        //ASSERT_EQ(i,out[i]);
    }
    assert(false);
}