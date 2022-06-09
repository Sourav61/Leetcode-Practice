class TextEditor {
public:
    stack<char> left;
    stack<char> right; 
    
    TextEditor() {
    }
    
    void addText(string text) {
        for(int i=0;i<text.size();i++){
            left.push(text[i]);
        }
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while(!left.empty() && k--){
            left.pop();
            cnt++;
        }

        return cnt;
    }
    
    string cursorLeft(int k) {
        while(!left.empty() && k--){
            char p = left.top();
            left.pop();
            right.push(p);
        }

        return Kleft();
    }
    
    string cursorRight(int k) {
        while(!right.empty() && k--){
            char p = right.top();
            right.pop();
            left.push(p);
        }

        return Kleft();
    }

    string Kleft(){
        int size = left.size();
        int cnt = min(10,size);

        string ans;
        while(cnt-- && !left.empty()){
            ans += left.top();
            left.pop();
        }

        reverse(ans.begin(), ans.end());

        for(int i=0;i<ans.size();i++){
            left.push(ans[i]);
        }

        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */