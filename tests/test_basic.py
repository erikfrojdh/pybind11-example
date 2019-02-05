from example import PyDetector
from example import add

def test_constructor():
    d = PyDetector()
    assert d.detId() == 5


def test_freestanding_add():
    assert add(5,6) == 11