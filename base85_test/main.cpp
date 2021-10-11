#include <UnitTest++/UnitTest++.h>
#include <../base85/base85.cpp>

SUITE(ConstructFirst)
{
	TEST(CorrectName) {
		Base85 obj("t.txt", "11.txt");
		CHECK(true);
	}
	TEST(JpgFile) {
		Base85 obj("t2.jpg", "11.txt");
		CHECK(true);
	}
	TEST(NoFile) {
		CHECK_THROW(Base85 obj("n.txt", "11.txt"), base85_error);
	}
	TEST(EmptyString) {
		CHECK_THROW(Base85 obj("", "11.txt"), base85_error);
	}
	TEST(NotPoint) {
		CHECK_THROW(Base85 obj("ttxt", "11.txt"), base85_error);
	}
	TEST(NotLetters) {
		CHECK_THROW(Base85 obj("...", "11.txt"), base85_error);
	}
	TEST(NotExtend) {
		CHECK_THROW(Base85 obj("t.", "11.txt"), base85_error);
	}
}

SUITE(ConstructSecond)
{
	TEST(CorrectName) {
		Base85 obj("t.txt", "new.txt");
		CHECK(true);
	}
	TEST(JpgFile) {
		Base85 obj("t.txt", "new.jpg");
		CHECK(true);
	}
	TEST(EmptyString) {
		CHECK_THROW(Base85 obj("t.txt", ""), base85_error);
	}
	TEST(NotPoint) {
		CHECK_THROW(Base85 obj("t.txt", "ttxt"), base85_error);
	}
	TEST(NotLetters) {
		CHECK_THROW(Base85 obj("t.txt", "..."), base85_error);
	}
	TEST(NotExtend) {
		CHECK_THROW(Base85 obj("t.txt", "t."), base85_error);
	}
}


int main(int argc, char **argv) {
	return UnitTest::RunAllTests();
}
