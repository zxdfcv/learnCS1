class MyCalendar {//��Ͷ���
    set<pair<int, int >> calendar;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto tar = calendar.lower_bound({end, 0} );//����fisrt element
        if (tar == calendar.begin() || ((--tar)->second <= start))//������ 
        {
            calendar.emplace(start, end);
            return true;
        }
        else
        {
            return false;
        }
    }//����STL
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
 //��treeSet(ʵ��Ϊ�����)
