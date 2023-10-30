/* Node is as follows:

struct Node
{
	int data, height;
	Node *left, *right;
	Node(int x)
	{
		data = x;
		height = 1;
		left = right = NULL;
	}
};

*/
Node * leftRotate(Node * cur) {
    Node * toreturn = cur -> right;
    Node * temp = cur -> right -> left;
    cur -> right -> left = cur;
    cur -> right = temp;
    
    return toreturn;
}

Node * rightRotate(Node * cur){
    Node * toreturn = cur -> left;
    Node * temp = cur -> left -> right;
    cur -> left -> right = cur;
    cur -> left = temp;
    
    return toreturn;
}

Node * deleteNode(Node * root, int data)
{
    function<Node *(Node *, int)> del = [&del](Node * cur, int data) -> Node * {
        if(cur == nullptr)
        return nullptr;
        
        if(cur -> data == data){
            if(cur -> left == nullptr and cur -> right == nullptr){
                
                delete(cur);
                return nullptr;
            }
            else if(cur -> left == nullptr){
                
                Node * toreturn = cur -> right;
                delete(cur);
                return toreturn;
            }
            else if(cur -> right == nullptr){
                
                Node * toreturn = cur -> left;
                delete(cur);
                return toreturn;
            }
            else{
                Node * next = cur -> left;
                
                while(next -> right != nullptr)
                next = next -> right;
                
                cur -> data = next -> data;
                
                cur -> left = del(cur -> left, cur -> data);
            }
        }
        else if(data < cur -> data){
            cur -> left = del(cur -> left, data);
        }
        else{
            cur -> right = del(cur -> right, data);
        }
        
        setHeights(cur);
        
        int left, right;
        left = right = 0;
        
        if(cur -> left != nullptr)
        left = cur -> left -> height;
        if(cur -> right != nullptr)
        right = cur -> right -> height;
        
        if(left - right > 1){
            
            left = right = 0;
            
            if(cur -> left -> left != nullptr)
            left = cur -> left -> left -> height;
            if(cur -> left -> right != nullptr)
            right = cur -> left -> right -> height;
            
            if(left - right >= 0){
                cur = rightRotate(cur);
            }
            else{
                cur -> left = leftRotate(cur -> left);
                cur = rightRotate(cur);
            }
        }
        else if(left - right < -1){
            left = right = 0;
            
            if(cur -> right -> right != nullptr)
            right = cur -> right -> right -> height;
            
            if(cur -> right -> left != nullptr)
            left = cur -> right -> left -> height;
            
            if(left - right <= 0){
                
                cur = leftRotate(cur);
            }
            else{
                cur -> right = rightRotate(cur -> right);
                cur = leftRotate(cur);
            }
        }
        return cur;
    };
    return del(root, data);
    
}
