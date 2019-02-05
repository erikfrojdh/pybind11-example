from example import PyDetector


def test_constructor():
    d = PyDetector()
    assert d.detId() == 5