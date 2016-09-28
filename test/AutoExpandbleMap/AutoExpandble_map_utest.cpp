#include <gtest/gtest.h>

#include "Map_test.h"

bool is_succeed(const DiscretePoint2D& Cell_coor, MapParams expected_param) {
  GridMap map(std::shared_ptr<GridCellFactory>(new TinyBaseCellFactory), {1,1,1});
  MapParams param = test_auto_expand(Cell_coor, map);
  return param == expected_param;
}

TEST(AutoExpandbleMapBaseTests, Expand_Right) {
  EXPECT_TRUE(is_succeed({2,0}, {1,4,0,0}));
}

TEST(AutoExpandbleMapBaseTests, Expand_Top) {
  EXPECT_TRUE(is_succeed({0,2}, {4,1,0,0}));
}

TEST(AutoExpandbleMapBaseTests, Expand_Left) {
  EXPECT_TRUE(is_succeed({-2,0}, {1,4,3,0}));
}

TEST(AutoExpandbleMapBaseTests, Expand_Down) {
  EXPECT_TRUE(is_succeed({0,-2}, {4,1,0,3}));
}

TEST(AutoExpandbleMapBaseTests, Expand_Right_Top) {
  EXPECT_TRUE(is_succeed({2,2}, {4,4,0,0}));
}

TEST(AutoExpandbleMapBaseTests, Expand_Right_Down) {
  EXPECT_TRUE(is_succeed({2,-2}, {4,4,0,3}));
}

TEST(AutoExpandbleMapBaseTests, Expand_Left_Top) {
  EXPECT_TRUE(is_succeed({-2,2}, {4,4,3,0}));
}

TEST(AutoExpandbleMapBaseTests, Expand_Left_Down) {
  EXPECT_TRUE(is_succeed({-2,-2}, {4,4,3,3}));
}

TEST(AutoExpandbleMapBaseTests, NoExpand) {
  EXPECT_TRUE(is_succeed({0,0}, {1,1,0,0}));
}

TEST(AutoExpandbleMapBaseTests, CheckCellsValue) {
  GridMap map(std::shared_ptr<GridCellFactory>(new TinyBaseCellFactory), {1,1,1});
  map.update_cell({5, 5}, {0.5, 0.5});
  bool not_change = test_CellValueNotChange(map);
  EXPECT_TRUE(not_change);
}

int main (int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
