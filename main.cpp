#include "qonboardplatforminputcontext.h"

#include <qpa/qplatforminputcontextplugin_p.h>
#include <QtCore/QStringList>

QT_BEGIN_NAMESPACE

class QOnboardPlatformInputContextPlugin : public QPlatformInputContextPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QPlatformInputContextFactoryInterface_iid FILE "onboard.json")

public:
    QOnboardPlatformInputContext *create(const QString&, const QStringList&) Q_DECL_OVERRIDE;
};

QOnboardPlatformInputContext *QOnboardPlatformInputContextPlugin::create(const QString& system, const QStringList& paramList)
{
    Q_UNUSED(paramList);

    if (system == QLatin1String("onboard")) {
        return new QOnboardPlatformInputContext;
    }

    return 0;
}

QT_END_NAMESPACE

#include "main.moc"
