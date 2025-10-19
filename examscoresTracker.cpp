class ExamTracker {
public:
    vector<long long> pre{0}, times{0};

    void record(int time, int score) {
        pre.push_back(pre.back() + score);
        times.push_back(time);
    }

    long long totalScore(int startTime, int endTime) {
        int i = lower_bound(times.begin(), times.end(), startTime) - times.begin();
        int j = upper_bound(times.begin(), times.end(), endTime) - times.begin();
        return pre[j - 1] - pre[i - 1];
    }
};
