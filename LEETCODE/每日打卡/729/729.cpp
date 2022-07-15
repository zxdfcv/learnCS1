class MyCalendar {//类和对象
    set<pair<int, int >> calendar;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto tar = calendar.lower_bound({end, 0} );//先排fisrt element
        if (tar == calendar.begin() || ((--tar)->second <= start))//迭代器 
        {
            calendar.emplace(start, end);
            return true;
        }
        else
        {
            return false;
        }
    }//巧用STL
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
 //用treeSet(实质为红黑树)
