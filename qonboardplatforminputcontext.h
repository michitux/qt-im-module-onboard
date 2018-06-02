#ifndef QONBOARDPLATFORMINPUTCONTEXT_H
#define QONBOARDPLATFORMINPUTCONTEXT_H

#include <qpa/qplatforminputcontext.h>

QT_BEGIN_NAMESPACE

class QDBusInterface;

class QOnboardPlatformInputContext : public QPlatformInputContext
{
    Q_OBJECT

public:
    QOnboardPlatformInputContext();
    ~QOnboardPlatformInputContext();

    bool isValid() const Q_DECL_OVERRIDE;
    void setFocusObject(QObject *object) Q_DECL_OVERRIDE;

    void showInputPanel() Q_DECL_OVERRIDE;
    void hideInputPanel() Q_DECL_OVERRIDE;
    bool isInputPanelVisible() const Q_DECL_OVERRIDE;

private:
    QDBusInterface *m_keyboardInterface;

    QObject *m_focusObject;
};

QT_END_NAMESPACE

#endif
