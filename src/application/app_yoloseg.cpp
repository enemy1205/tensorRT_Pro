#include <builder/trt_builder.hpp>
#include <common/ilogger.hpp>
#include <infer/trt_infer.hpp>

using namespace std;
using namespace cv;

int app_yoloseg() {
  TRT::set_device(0);
  int test_batch_size = 8;
  TRT::Mode mode = TRT::Mode::FP16;
  string onnx_file = "/home/enemy1205/gait_-recognition-v3/doc/models/yolov8s-seg.onnx";
  string model_file = "yolov8s-seg.engine";
  if (not iLogger::exists(model_file)) {
    TRT::compile(mode,             // FP32、FP16、INT8
                 test_batch_size,  // max batch size
                 onnx_file,        // source
                 model_file);
  }
  return 0;
}