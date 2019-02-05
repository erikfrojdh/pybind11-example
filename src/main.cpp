#include <pybind11/pybind11.h>
#include <iostream>
int add(int i, int j)
{
    return i + j;
}

namespace py = pybind11;

class Detector
{
  public:
    Detector(int det_id) : det_id_(det_id)
    {
    }
    int detId() const
    {
        return det_id_;
    }
    void setDetId(int id)
    {
        det_id_ = id;
    }

    int getExposureTime() const
    {
        std::cout << "Reading exposure time: " << exposure_time_ << " \n";
        return exposure_time_;
    }
    void setExposureTime(int t)
    {
        std::cout << "Setting exposure time: " << t << " \n";
        exposure_time_ = t;
    }

  private:
    int det_id_ = 0;
    int exposure_time_ = 0;
};

PYBIND11_MODULE(CompiledModule, m)
{
    m.doc() = R"pbdoc(
        Pybind11 example plugin
        -----------------------
        .. currentmodule:: CompiledModule
        .. autosummary::
           :toctree: _generate
           add
           subtract
    )pbdoc";

    m.def("add", &add, R"pbdoc(
        Add two numbers
        Some other explanation about the add function.
    )pbdoc");

    m.def("subtract", [](int i, int j) { return i - j; }, R"pbdoc(
        Subtract two numbers
        Some other explanation about the subtract function.
    )pbdoc");

    py::class_<Detector>(m, "Detector")
        .def(py::init<int>())
        .def("detId", &Detector::detId)
        .def_property("exposure_time",
                      py::cpp_function(&Detector::getExposureTime),
                      py::cpp_function(&Detector::setExposureTime))
        .def_property("det_id",
                      py::cpp_function(&Detector::detId),
                      py::cpp_function(&Detector::setDetId));

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
