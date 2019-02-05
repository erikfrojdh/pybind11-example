
from CompiledModule import Detector

class PyDetector(Detector):
    def __init__(self):
        super().__init__(5)
        print("PyDetector created")

    @property
    def python_detid(self):
        return self.detId()

    @property
    def something(self):
        return 5