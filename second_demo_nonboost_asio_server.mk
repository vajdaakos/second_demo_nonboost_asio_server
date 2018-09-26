##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=second_demo_nonboost_asio_server
ConfigurationName      :=Debug
WorkspacePath          :=/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo
ProjectPath            :=/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Vajda Ákos Péter
Date                   :=03/11/18
CodeLitePath           :=/home/akos/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="second_demo_nonboost_asio_server.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lssl -lcrypto -lpthread -lboost_system
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Server.cpp$(ObjectSuffix) $(IntermediateDirectory)/Signer_and_verifier.cpp$(ObjectSuffix) $(IntermediateDirectory)/Connection.cpp$(ObjectSuffix) $(IntermediateDirectory)/Message.cpp$(ObjectSuffix) $(IntermediateDirectory)/Auth_answer_message.cpp$(ObjectSuffix) $(IntermediateDirectory)/Job_send_message.cpp$(ObjectSuffix) $(IntermediateDirectory)/close_connection.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Server.cpp$(ObjectSuffix): Server.cpp $(IntermediateDirectory)/Server.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server/Server.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Server.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Server.cpp$(DependSuffix): Server.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Server.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Server.cpp$(DependSuffix) -MM Server.cpp

$(IntermediateDirectory)/Server.cpp$(PreprocessSuffix): Server.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Server.cpp$(PreprocessSuffix) Server.cpp

$(IntermediateDirectory)/Signer_and_verifier.cpp$(ObjectSuffix): Signer_and_verifier.cpp $(IntermediateDirectory)/Signer_and_verifier.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server/Signer_and_verifier.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Signer_and_verifier.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Signer_and_verifier.cpp$(DependSuffix): Signer_and_verifier.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Signer_and_verifier.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Signer_and_verifier.cpp$(DependSuffix) -MM Signer_and_verifier.cpp

$(IntermediateDirectory)/Signer_and_verifier.cpp$(PreprocessSuffix): Signer_and_verifier.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Signer_and_verifier.cpp$(PreprocessSuffix) Signer_and_verifier.cpp

$(IntermediateDirectory)/Connection.cpp$(ObjectSuffix): Connection.cpp $(IntermediateDirectory)/Connection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server/Connection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Connection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Connection.cpp$(DependSuffix): Connection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Connection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Connection.cpp$(DependSuffix) -MM Connection.cpp

$(IntermediateDirectory)/Connection.cpp$(PreprocessSuffix): Connection.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Connection.cpp$(PreprocessSuffix) Connection.cpp

$(IntermediateDirectory)/Message.cpp$(ObjectSuffix): Message.cpp $(IntermediateDirectory)/Message.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server/Message.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Message.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Message.cpp$(DependSuffix): Message.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Message.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Message.cpp$(DependSuffix) -MM Message.cpp

$(IntermediateDirectory)/Message.cpp$(PreprocessSuffix): Message.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Message.cpp$(PreprocessSuffix) Message.cpp

$(IntermediateDirectory)/Auth_answer_message.cpp$(ObjectSuffix): Auth_answer_message.cpp $(IntermediateDirectory)/Auth_answer_message.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server/Auth_answer_message.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Auth_answer_message.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Auth_answer_message.cpp$(DependSuffix): Auth_answer_message.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Auth_answer_message.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Auth_answer_message.cpp$(DependSuffix) -MM Auth_answer_message.cpp

$(IntermediateDirectory)/Auth_answer_message.cpp$(PreprocessSuffix): Auth_answer_message.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Auth_answer_message.cpp$(PreprocessSuffix) Auth_answer_message.cpp

$(IntermediateDirectory)/Job_send_message.cpp$(ObjectSuffix): Job_send_message.cpp $(IntermediateDirectory)/Job_send_message.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server/Job_send_message.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Job_send_message.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Job_send_message.cpp$(DependSuffix): Job_send_message.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Job_send_message.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Job_send_message.cpp$(DependSuffix) -MM Job_send_message.cpp

$(IntermediateDirectory)/Job_send_message.cpp$(PreprocessSuffix): Job_send_message.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Job_send_message.cpp$(PreprocessSuffix) Job_send_message.cpp

$(IntermediateDirectory)/close_connection.cpp$(ObjectSuffix): close_connection.cpp $(IntermediateDirectory)/close_connection.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/akos/Dokumentumok/Forráskódok/projektek_laptopról2/pprojectdemo/second_demo_nonboost_asio_server/close_connection.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/close_connection.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/close_connection.cpp$(DependSuffix): close_connection.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/close_connection.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/close_connection.cpp$(DependSuffix) -MM close_connection.cpp

$(IntermediateDirectory)/close_connection.cpp$(PreprocessSuffix): close_connection.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/close_connection.cpp$(PreprocessSuffix) close_connection.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


