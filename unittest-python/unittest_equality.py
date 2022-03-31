import unittest


class EqualityTest(unittest.TestCase):
    def test_expect_equal(self):
        self.assertEqual(1, 3 - 2)

    def test_expect_equal_failed(self):
        self.assertEqual(2, 3 - 2)

    def test_expect_notequal(self):
        self.assertNotEqual(2, 3 - 2)

    def test_expect_notequal_failed(self):
        self.assertNotEqual(1, 3 - 2)
