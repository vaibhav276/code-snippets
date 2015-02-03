#ifndef __DEBUGGABLE_H
#define __DEBUGGABLE_H

class Debuggable {
    protected:
        bool m_bDebug;
    public:
		void enableDebugging() {
		    m_bDebug = true;
		}
		void disableDebugging() {
		    m_bDebug = false;
		}
		bool isDebugging() {
		    return m_bDebug;
		}
};
#endif