// Copyright 2022 PingCAP, Ltd.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <Interpreters/ExternalLoaderConfigRepository.h>
#include <Interpreters/IRuntimeComponentsFactory.h>
#include <Interpreters/SecurityManager.h>

namespace DB
{
/** Default implementation of runtime components factory
  * used by native server application.
  */
class RuntimeComponentsFactory : public IRuntimeComponentsFactory
{
public:
    std::unique_ptr<ISecurityManager> createSecurityManager() override
    {
        return std::make_unique<SecurityManager>();
    }

    std::unique_ptr<IExternalLoaderConfigRepository> createExternalDictionariesConfigRepository() override
    {
        return std::make_unique<ExternalLoaderConfigRepository>();
    }

    std::unique_ptr<IExternalLoaderConfigRepository> createExternalModelsConfigRepository() override
    {
        return std::make_unique<ExternalLoaderConfigRepository>();
    }
};

} // namespace DB
