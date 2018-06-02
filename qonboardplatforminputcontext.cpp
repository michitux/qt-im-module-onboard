#include "qonboardplatforminputcontext.h"

#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusReply>

QOnboardPlatformInputContext::QOnboardPlatformInputContext()
    : m_focusObject(0)
{
    m_keyboardInterface = new QDBusInterface("org.onboard.Onboard", "/org/onboard/Onboard/Keyboard", "org.onboard.Onboard.Keyboard", QDBusConnection::sessionBus(), this);
}

QOnboardPlatformInputContext::~QOnboardPlatformInputContext()
{
}

bool QOnboardPlatformInputContext::isValid() const
{
    return m_keyboardInterface->isValid();
}

void QOnboardPlatformInputContext::setFocusObject(QObject *object)
{
    m_focusObject = object;
}

void QOnboardPlatformInputContext::showInputPanel()
{
    m_keyboardInterface->call("Show");
}

void QOnboardPlatformInputContext::hideInputPanel()
{
    m_keyboardInterface->call("Hide");
}

bool QOnboardPlatformInputContext::isInputPanelVisible() const
{
    const QDBusReply<bool> reply = m_keyboardInterface->call("Visible");

    if (reply.isValid())
        return reply.value();
    else
        return false;
}
