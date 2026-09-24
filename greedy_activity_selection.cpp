#include <algorithm>
#include <iostream>
#include <vector>

// 活动：start 为开始时间，finish 为结束时间。
struct Activity {
    int start;
    int finish;
};

// 贪心策略：每次选择结束时间最早、且不与已选活动冲突的活动。
std::vector<Activity> selectActivities(std::vector<Activity> activities) {
    std::sort(activities.begin(), activities.end(),
              [](const Activity& a, const Activity& b) {
                  return a.finish < b.finish;
              });

    std::vector<Activity> selected;
    int lastFinish = -1;

    for (const auto& activity : activities) {
        if (activity.start >= lastFinish) {
            selected.push_back(activity);
            lastFinish = activity.finish;
        }
    }
    return selected;
}

int main() {
    std::vector<Activity> activities = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 9},
        {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 14}, {12, 16}
    };

    const auto selected = selectActivities(activities);

    std::cout << "选择的活动（开始时间, 结束时间）：\n";
    for (const auto& activity : selected) {
        std::cout << "(" << activity.start << ", " << activity.finish << ")\n";
    }
    std::cout << "共选择 " << selected.size() << " 个互不冲突的活动。\n";

    return 0;
}
