#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
struct process{
    int id;
    int bt;
    int at;
    int in;
    int ct;
    int wt;
    int rt;
    bool status;
    int rem;
};
void rr(vector<process>& pr,int tq){
    int n = pr.size();
    int ti = 0;
    queue<process*> readyqueue; //queue to store
    vector<int> eo; //execution order
    for(int i = 0;i < n;i++){
        pr[i].in = -1;
        pr[i].ct = -1;
        pr[i].wt = -1;
        pr[i].rt = -1;
        pr[i].status = false;
        pr[i].rem = pr[i].bt;
    }
    int ep = 0;
    while(ep < n){
        for(int i = 0;i < n;i++){
            if(pr[i].at <= ti && !pr[i].status){
                if(pr[i].in == -1){
                    pr[i].in = ti;
                    pr[i].rt = ti-pr[i].at;
                }
                readyqueue.push(&pr[i]);
                pr[i].status = true;
            }
        }
        if(readyqueue.empty()){
            ti++;
            continue;
        }
        process *cp = readyqueue.front();
        readyqueue.pop();
        int rem = cp->rem;
        eo.push_back(cp->id);
        if(rem <= tq){
            cp->ct = ti+rem;
            cp->rem = 0;
            ep++;
            ti = ti + rem;
        }
        else{
            cp->rem = cp->rem - tq;
            ti = ti + tq;
        }
        
        for(int i = 0;i < n;i++){
            if(pr[i].at <= ti && !pr[i].status){
                readyqueue.push(&pr[i]);
                pr[i].status = true;
            }
        }
        if(cp->rt > 0)
            readyqueue.push(cp);
    }
    for(int i = 0;i < n;i++)
        cout << eo[i] << " ";
    cout << endl;
    float tat = 0.0;
    for(int i = 0;i < n;i++){
        pr[i].ct = pr[i].ct - pr[i].at;
        tat = tat + pr[i].at;
        cout << pr[i].id << " " << pr[i].ct << endl;
    }
    float wt = 0.0;
    for(int i = 0;i < n;i++){
        pr[i].wt = pr[i].ct - pr[i].bt;
        wt = wt + pr[i].wt;
        cout << pr[i].id << " " << pr[i].wt << endl;
    }
    double atat = tat/n;
    double awt = wt/n;
    cout << atat << endl;
    cout << awt << endl;
}
int main(){
    int tq;
    cin >> tq;
    int p;
    cin >> p;
    vector<process> pr(p);
    for(int i = 0;i < p;i++){
        cin >> pr[i].bt;
        pr[i].id = i;
    }
    for(int i = 0;i < p;i++){
        cin >> pr[i].at;
    }
    rr(pr,tq);
    return 0;
}
