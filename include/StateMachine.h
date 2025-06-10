#pragma once
#include<memory>
#include<stack>
#include "state.h"
using namespace std;
namespace Dat{
    typedef unique_ptr<State> StateRef;
    class StateMachine{
    public:
        StateMachine(){};
        ~StateMachine(){};

        void AddState(StateRef newState, bool isReplacing = true);
        void RemoveState();
        void ProcessStateChanges();
        StateRef &GetActiveState();
    private:
        stack<StateRef> _states;
        StateRef _newState;

        bool _isRemoving;
        bool _isAdding;
        bool _isReplacing;
    };
}