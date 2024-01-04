#include "fuzztest/fuzztest.h"
#include "fuzztest/googletest_fixture_adapter.h"
#include "gtest/gtest.h"

#include "character.hpp"

class TestCharacter : public ::testing::Test {
protected:
    Character character;

    virtual void SetUp() {
        character = Character();
    }

};

class TestCharacterFuzz : public fuzztest::PerIterationFixtureAdapter<TestCharacter> {
public:
    void LevelCanBeSet(int level) {
        ASSERT_TRUE(level>0);
        bool ret = character.set_level(level);
        EXPECT_TRUE(ret);
    }

    void HealthIsFactorTenOfLevel(int level) {
        character.set_level(level);
        EXPECT_EQ(character.get_health(), level * 10);
    }

    void IfSetLevelReturnsTrueLevelIsSetToNewValue(int level) {
        bool ret = character.set_level(level);
        if (ret) {
            EXPECT_EQ(character.get_level(), level);
        }
    }

    void LevelCannotBeSetToNegativeValue(int level) {
        ASSERT_TRUE(level<1);
        bool ret = character.set_level(level);
        EXPECT_FALSE(ret);
    }
};

FUZZ_TEST_F(TestCharacterFuzz, LevelCanBeSet).WithDomains(/*level=*/fuzztest::Positive<int>());
FUZZ_TEST_F(TestCharacterFuzz, HealthIsFactorTenOfLevel).WithDomains(/*level=*/fuzztest::Positive<int>());
FUZZ_TEST_F(TestCharacterFuzz, IfSetLevelReturnsTrueLevelIsSetToNewValue).WithDomains(/*level=*/fuzztest::Arbitrary<int>());
FUZZ_TEST_F(TestCharacterFuzz, LevelCannotBeSetToNegativeValue).WithDomains(/*level=*/fuzztest::NonPositive<int>());

