#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

auto cmp = [](pair<int ,long long> left, pair<int, long long> right) {
    if (left.second == right.second) {
        return left.first > right.first;
    }

    return left .second > right.second;
};


class JobQueue {
private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;

    void WriteResponse() const {
        for (int i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for (int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs() {
        // TODO: replace this code with a faster algorithm.
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < num_workers_; i++) {
            pq.push(make_pair(i, 0));
        }
        auto next_worker = pq.top();
        for (int i = 0; i < jobs_.size(); ++i) {
            next_worker = pq.top();
            assigned_workers_[i] = next_worker.first;
            start_times_[i] = next_worker.second;
            pq.pop();
            pq.push(make_pair(next_worker.first, next_worker.second + jobs_[i]));
        }
    }

public:
    void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
