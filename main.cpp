#include <iostream>

using namespace std;
#define nl "\n"
#define M_S std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template<class t>
class stack {
    struct node {
        t type;
        node *next;
    };
    node *top;
public:
    stack() {
        top = NULL;
    }

    void push(t el) {
        node *elm = new node;
        elm->next = top;
        elm->type = el;
        top = elm;
    }

    bool empty() {
        return top == NULL;
    }

    void pop() {
        if (empty()) {
            cout << "STACK is empty" << nl;
            return;
        }
        node *temp = top;
        top = top->next;
        delete temp;
    }

    void print() {
        node *temp = top;
        cout << "[ ";
        while (temp != NULL) {
            cout << temp->type << ' ';
            temp = temp->next;
        }
        cout << ']' << nl;
        delete temp;
    }

    void Top() {
        if (empty()) {
            cout << "STACK is empty" << nl;
            return;
        }
        cout << top->type << nl;
    }

    void clear() {
        while (top != NULL) {
            node *cur = top;
            top = top->next;
            delete cur;
        }
    }
};

template<class t>
class queue {
    struct node {
        t type;
        node *next;
    };
    node *front, *back;
    int l;
public:
    queue() {
        l = 0;
        front = back = NULL;
    }

    bool empty() {
        return back == NULL;
    }

    void push(t el) {
        if (empty()) {
            front = new node;
            front->type = el;
            front->next = NULL;
            back = front;
        } else {
            node *newel = new node;
            newel->type = el;
            newel->next = NULL;
            back->next = newel;
            back = newel;
        }
    }

    void pop() {
        if (empty())
            cout << "Queue is empty\n";
        else if (front == back)
            front = back = NULL;
        else {
            node *temp = front;
            front = front->next;
            delete temp;
            temp = NULL;
        }
    }

    t top() {
        return front->type;
    }

    void clear() {
        while (front != NULL) {
            node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void print() {
        cout << '[';
        node *cur = front;
        while (cur != NULL) {
            cout << cur->type << ' ';
            cur = cur->next;
        }
        cout << "]\n";
    }
};

template<class t>
class linkedlist {
    int le = 0;
    struct node {
        t type;
        node *next;
    };
    node *back, *front;
public:
    linkedlist() {
        back = NULL;
        front = NULL;
    }

    bool empty() {
        return le == 0;
    }

    void pushfront(t el) {
        if (le == 0) {
            back = new node;
            back->type = el;
            back->next = NULL;
            front = back;
        } else {
            node *newel = new node;
            newel->type = el;
            newel->next = front;
            front = newel;
        }
        le++;
    }

    void pushback(t el) {
        if (le == 0) {
            back = new node;
            back->type = el;
            back->next = NULL;
            front = back;
        } else {
            node *newel = new node;
            newel->type = el;
            newel->next = NULL;
            back->next = newel;
            back = newel;
        }
        le++;
    }

    void push(int pos, t el) {
        if (pos < 0 || pos > le) {
            cout << "Out of range\n";
            return;
        } else if (pos == 0)
            pushfront(el);
        else if (pos == le)
            pushback(el);
        else {
            node *cur = front;
            for (int i = 1; i < pos; i++)
                cur = cur->next;
            node *newel = new node;
            newel->next = cur->next;
            newel->type = el;
            cur->next = newel;
        }
        le++;
    }

    void popback() {
        if (le == 1) {
            front = back = NULL;
            le--;
            return;
        }
        node *cur = front, *prev;
        while (cur->next != NULL) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        back = prev;
        delete cur;
        le--;
    }

    void popfront() {
        if (le == 1) {
            front = back = NULL;
            le--;
            return;
        }
        node *temp = front;
        front = front->next;
        delete temp;
        le--;
    }

    void pop(t el) {
        node *cur = front, *prev;
        while (cur != NULL && cur->type != el) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL)
            return;
        else if (cur == back)
            popback();
        else if (cur == front)
            popfront();
        else {
            prev->next = cur->next;
            le--;
            delete cur;
        }
    }

    int size() {
        return le;
    }

    void reverse() {
        node *cur = front, *next = front, *prev = NULL;
        while (cur != NULL) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        back = front;
        front = prev;
        delete cur;
        delete next;
    }

    void clear() {
        node *cur = front;
        while (front != NULL) {
            cur = front;
            front = front->next;
            delete cur;
        }
        le = 0;
    }

    void print() {
        node *cur = front;
        cout << '[';
        while (cur != NULL) {
            cout << cur->type << ' ';
            cur = cur->next;
        }
        cout << "]\n";
    }

};

template<class t>
class bst {
    struct node {
        t type;
        node *right, *left;
    };
    node *root = NULL, *prev;
public:
    node *insert(node *cur, t el) {
        if (cur == NULL) {
            node *newel = new node;
            newel->type = el;
            newel->left = NULL;
            newel->right = NULL;
            cur = newel;

        } else if (el < cur->type) {
            cur->left = insert(cur->left, el);
        } else {
            cur->right = insert(cur->right, el);
        }
        return cur;
    }

    void insert(t el) {
        root = insert(root, el);
    }

    void pre(node *cur) {
        if (cur != NULL) {
            cout << cur->type << ' ';
            pre(cur->left);
            pre(cur->right);
        }
    }

    void pre() {
        node *cur = root;
        pre(cur);
        cout << nl;
    }

    void inorder(node *cur) {
        if (cur != NULL) {
            inorder(cur->left);
            cout << cur->type << ' ';
            inorder(cur->right);
        }
    }

    void inorder() {
        node *cur = root;
        inorder(cur);
        cout << nl;
    }

    void post(node *cur) {
        if (cur != NULL) {
            post(cur->left);
            post(cur->right);
            cout << cur->type << ' ';
        }
    }

    void post() {
        node *cur = root;
        post(cur);
        cout << nl;
    }

    void breadth() {
        queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            cout << q.top()->type << ' ';
            if (q.top()->left != NULL)
                q.push(q.top()->left);
            if (q.top()->right != NULL)
                q.push(q.top()->right);
            q.pop();
        }
        cout << nl;
    }

    bool find(node *cur, t el) {
        if (cur != NULL) {
            if (cur->type == el)
                return true;
            else if (cur->type > el)
                return find(cur->left, el);
            else
                return find(cur->right, el);
        }
        return false;
    }

    bool find(t el) {
        return find(root, el);
    }

    node *maxel(node *cur) {
        if (cur == NULL)
            return NULL;
        if (cur->right == NULL)
            return cur;
        return maxel(cur->right);
    }

    node *maxel() {
        return maxel(root);
    }

    node *minel(node *cur) {
        if (cur == NULL)
            return NULL;
        if (cur->left == NULL)
            return cur;
        return minel(cur->left);
    }

    node *minel() {
        return minel(root);
    }

    node *erase(node *r, t el) {
        if (r == NULL)
            return NULL;
        else if (r->type > el) {
            prev = r;
            r->left = erase(r->left, el);
        } else if (r->type < el) {
            prev = r;
            r->right = erase(r->right, el);
        } else {
            if (r->right == NULL && r->left == NULL) {
                delete r;
                r = NULL;
            } else if (r->right == NULL && r->left != NULL) {
                node *cur = r;
                if (r->type >= prev->type)
                    prev->right = r->left;
                else
                    prev->left = r->left;
                r = r->left;
                delete cur;
            } else if (r->right != NULL && r->left == NULL) {
                node *cur = r;
                if (r->type >= prev->type)
                    prev->right = r->right;
                else
                    prev->left = r->right;
                r = r->right;
                delete cur;
            } else {
                node *cur = minel(r->right);
                r->type = cur->type;
                r->right = erase(r->right, r->type);
            }
        }
        return r;
    }

    void erase(t el) {
        prev == new node;
        erase(root, el);
    }
};

void stacktest(stack<int> &s) {
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.print();
    s.Top();
    s.pop();
    s.Top();
    s.pop();
    s.Top();
}

void queuetest(queue<int> &q) {
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    q.print();
    cout << q.top() << nl;
    q.pop();
    cout << q.top() << nl;
    q.pop();
    q.pop();
}

void linkedlisttest(linkedlist<int> &l) {
    l.pushback(4);
    l.pushback(5);
    l.pushfront(1);
    l.push(1, 2);
    l.push(2, 3);
    l.pushback(7);
    l.push(5, 6);
    l.print();
    l.popback();
    l.print();
    l.popfront();
    l.print();
    l.pop(2);
    l.print();
    l.pop(4);
    l.print();
    l.pop(5);
    l.print();
    l.pop(7);
    l.print();
    cout << l.size() << nl;
    l.push(1, 5);
    l.print();
    cout << l.size() << nl;
    l.clear();
    l.print();
    l.pushback(3);
    l.pushback(4);
    l.pushback(5);
    l.pushfront(2);
    l.pushfront(1);
    l.print();
    l.reverse();
    l.print();
    cout << l.size() << nl;
}

void bsttest(bst<int> &b) {
    b.insert(7);
    b.insert(9);
    b.insert(2);
    b.insert(14);
    b.insert(5);
    b.insert(1);
    b.pre();
    b.post();
    b.inorder();
    b.breadth();
    b.erase(2);
    b.breadth();
    cout << b.find(7) << ' ' << b.find(14) << ' ' << b.find(5) << ' ' << b.find(3) << nl;
}

int main() {
    M_S
    bst<int> b;
    bsttest(b);
}