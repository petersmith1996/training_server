#include <iostream>
#include <cstdio>
#include <sys/ioctl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <wait.h>
#include <stdio.h>
#include <string.h>
#include <thread>
#include <vector>
#include <errno.h>
#include <unordered_map>
#include <stdint.h>
#include <malloc.h>

#include <bitset>
#include <sstream>
#include <iomanip>

#include <json-c/json.h>
#include <json-c/arraylist.h>

#include "sample/j2735.h"

#include "tr_MessageFrame.h"
#include "messageProcessor.h"
#include "asnMessageProcessor.h"


#include <typeinfo>

using namespace std;
using namespace training;


char bsm_tmp[669]= "001480FA5B1C007F54AFEEE5B1E617DB921E8B092DC8227FFFF00067F1FDFA1FA1007FFF80005D0F6202031882C0FCFFC0434FB7FFFC0FA6CC0A10FBDFFFC0F813C10E6FBFFFFC0F585C183CFBFFFFC0F32641F36FBDFFFC0F0C342590FB1FFFC0EE6DC2C0AFABFFFC0EBA8C33DCFA7FFFC0E93FC3AE4FA3FFFC0E670C432AFA1FFFC0E3F4C4A42FA3FFFC0E17845150FA1FFFC0DF18C5816F9FFFFC0DC8FC5F90F9FFFFC0DA3FC6684FA1FFFC0D7E646D7EF9FFFFC0D5A34744AFA3FFFC0D328C7BBCFA1FFFC0D0C648288F9FFFFC0CE4E489CAF9FFFFC0CBFDC9084FA9FFFC0C97AC9588FA3FFFC0C72049C12F9FFFFC00104200000000810800200C000003014082805773B9B9C6A9F3298083F616926CF279828FEDC49D81849DB36ACC3A1031CDBDCB33C0800A48031D07BF3AD6F14C452052048CBA8A95559B8ECB8F30DD1318DD385CB6F0264EA06879B2";
char map_tmp[2387] = "001284A5080101901DC01DC02A5B199945B92512E88A5812C028D047830050000008000728000000034000000010004AF0011A9457B4088142BDBF436E15FD5A03FCAEFA719B657D1085202BFB8407F82546000143009000000400032BCAEC42035FCCA05610004AFC7105E857B4088142BDBAC36E024C500018300D000000800072BC2CC3C735FCEE05350004AFC4D062A57B49881F2BDF4C38F95FDA203FCAF0A31A6857D1085092BFB440850254A000143011000000A00072BBA6C36E35FD1204DD0004AFC29066C57B49881F2BDF4C38F95FDA20428AF0B31A5257D1085142BFB4407F8A54E000152E440000180A8000001000395D97218D9AFE890242800257DF983582BDA4C40F95EF821C7CAFED101FE578598D342BE91428A15FDC6042812E44000000224000000015EEF627C9AFE4102C6800200244000000015F4D22BF5AFE4102F4800200264000000015F8E22EBDAFE410320800200284000000015FD3231DDAFE1D030A80021842800000080031400000001A0000000080025000000002C712C5DD16208E13CCB0207012058D9E874C2C081C048024C4400203089000000400062C355C48FB6052A03210004B08A905205810380902C42C42741603EA0240B1BF10DA25810C807A04A9200040611A0000010000C586018A4B6C0A54059200096117609E4B020701365887384E82C07D404816382A1B70B022B00DE0972800070C2440000008000CB0AC116C2D814180B140012C22EC13C96040E026CB112F09A40914200000031200000000B10F90BE6D815C80DE40010032200000000B123B09A4D816580E940010033200000000B136B078ED816E80F440010C41400000200028B0A9EEEA0D80DF7E6F40012C2EF3AEB161519DB80B0D9EEA04580A07F002C473B86B961E99CB2CB0F5EE5AC5878B72C02C2643BF5960281FC00122300002188480000020001161A65E035B01D0FCF48002585DE75D62C2D43B86825C500008310D0000008000A2C3D33C543603A1F9BD0004B0BBCEBC25852B76CA2C324BA6596023DFC00B1188E154587B772D62C3CEB965961E75CB00B095CEFEC580A17EE90489400008622200000140014588B279446C0743F3D2000961779D758B0A56ED945864974D62C050BF80162311C2A8B0F6EE5AC5879D72CB2C3D7B965961295DFD8B0140FDD4291380001499900000622A00000040006589FD7A016C0623F32200096170DD758B0A7AED94585DE749E049990000002890000000058454760D6C04C3F7A200080291000000005830075456C04C3F8020008029900000000581F474A96C04BBF802000802A100000000580A073EC6C05DBF85A0008630A0000002000C50000000068000000020009400000000AE0EAEC04576D978A82BF8BBFA115BE79CB00AFE40FE6E0971100040C62400000100018AEF3CF33AD7ED87F1640012BDEC3E6A15FC39FD0CAED8EF19457F177F432B7ABB98C95FC39FD3412248000818C68000006000315E121E2CDAFDB2FE2C800257BE97CBE2BF873FA715DB1DE328AFE1CFE9A56F4573192BF8BBFA68A4CA0000D2268000018C88000001000195E49DDE75AFDA0FE16800257BE97CC92BF873FA715DA69E43012A84000000E24000000015D5A9F8B1AFC6EFD22800200E44000000015D36DFBA5AFC70FD4E8002";
char spat_tmp[261] = "00137F001880EE00EE01040067C026EF80761E9D4A5064C791500410C000280100183991635402043001810040061E9D4A5064C791500C11C0002801001839916354040470000A0040061E9D4A5064C791501410C000280100183991635406043001810040061E9D4A5064C791501C10C00924010018399163540804300249004000";

uint8_t bsm_encodedMessage_sample[334];
uint8_t map_encodedMessage_sample[1193];
uint8_t spat_encodedMessage_sample[130];


std::string getUtcTimeStr(){
    time_t now = time(0);
    tm* now_tm = gmtime(&now);
    char utc_time[64];
    strftime(utc_time, sizeof(utc_time), "%Y%m%d_%X", now_tm);

    return utc_time;
}

class clientData{
public:
    int clnt_cnt;
    char ID[16];
    int seq = 0;
    int sock;
    char recv_buffer[1024];
    int conn_state = 0;
    vector<string> recv_log;
    vector<string> send_log;
    bool sign_succ = false;
    bool sign = false;
    bool denied = false;

    uint8_t pre_recv_seq;
    uint8_t pre_send_seq;
};

class clientManager{
public:
    int simulator_sock;
    int total_clnt_cnt = 0;
    int clnt_acpt_idx = 0;
    vector<thread> workers;
    unordered_map<string, clientData> clientMap;
    unordered_map<string, vector<string>> msgLog;
    vector<string> access_log;
    vector<string> whole_log;
    DATA_MAP map;
    DATA_SPAT spat;
    DATA_BSM bsm;
    int cnt = 0;

    void run(){
        thread run(&clientManager::task_accept, this);

        //run.join();
        //printf("accept task done\n");
        run.detach();
    }

    void logger(vector<string> log){

    }

    void task_accept(){
        struct sockaddr_in client_addr;
        //memset(&client_addr, 0x0, sizeof(client_addr));
        unsigned int  addr_len;

        int i = 0;
        while(1){
            int accept_sock;
            printf("waiting for server..\n\n");
            accept_sock = accept(simulator_sock, (struct sockaddr *)&client_addr, &addr_len);
            clientData CD;
            CD.sock = accept_sock;
            CD.clnt_cnt = clnt_acpt_idx;
            clnt_acpt_idx++;
            total_clnt_cnt++;

            memcpy(CD.ID, "server", sizeof("server"));

            clientMap[CD.ID] = CD;

            thread worker(&clientManager::work, this, &clientMap[CD.ID]);
            worker.detach();

            i++;
        }
        
    }

    void remove_client(string ID){
        close(clientMap[ID].sock);
        clientMap.erase(ID);
        cout << "client " << ID << " removed" << endl;
    }

    void work(clientData* CD){
        CD->conn_state = 1;
        int num = CD->clnt_cnt;
        thread recv_thread(&clientManager::task_recv, this, CD);
        thread send_thread(&clientManager::task_send, this, CD);

        pthread_t H_recv = recv_thread.native_handle();
        pthread_t H_send = send_thread.native_handle();

        recv_thread.join();
        cout << "worker kill recv thread" << endl;

        pthread_cancel(H_send);
        send_thread.join();
        cout << "send_thread end" << endl;


        string leave;
        leave = getUtcTimeStr() + " leave: " + (string)CD->ID;
        cout << leave << endl;
        access_log.push_back(leave);

        whole_log.push_back(leave);

        close(CD->sock);

        clientMap.erase(CD->ID);
    }

    void task_send(clientData* CD){
        struct timespec begin;
        struct timespec end;
        char msg[64];
        clock_gettime(CLOCK_MONOTONIC, &begin);
        clock_gettime(CLOCK_MONOTONIC, &end);
        while(1){
            //try{
                if (CD->sign_succ){
                    if(((end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec) / 1000000000.0)<1){
                        clock_gettime(CLOCK_MONOTONIC, &end);
                    }
                    else{
                        clock_gettime(CLOCK_MONOTONIC, &begin);
                        try{
                            memset(msg, 0x0, sizeof(msg));
                            /*
                            St_SERVER_OR_CLIENT_JSON_DATA json_data_SPAT = messageProcessor::set_JSON_DATA_SPAT();

                            uint8_t* serial_Json_DATA = (uint8_t*)messageProcessor::serialize_JSON_DATA(json_data_SPAT);
                            int serial_Json_DATA_Length = HEADER_SIZE + json_data_SPAT.header.PayloadLength;
                            */

                            St_SIMULATOR_TX_J2735_DATA data = messageProcessor::set_SIMULATOR_TX_DATA(MESSAGE_ID_VALUE_MAP, map_encodedMessage_sample, sizeof(map_encodedMessage_sample));

                            data.header.Sequence = ++CD->pre_send_seq;
                            int data_size = MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG + data.payload.EncodedMessageLength;

                            uint8_t* serial_DATA = (uint8_t*)malloc(data_size);

                            memcpy(serial_DATA, &data, MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG);
                            memcpy(serial_DATA + MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG, data.payload.EncodedMessage, data.payload.EncodedMessageLength);

                            //printf("send EncodedMessage:\n");
                            //for(int i = 0; i<4; i++){
                                //printf("%02x", *(serial_DATA + MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG+i) );
                            //}
                            //printf("\n");

                            int ret = send(CD->sock, serial_DATA, data_size, MSG_NOSIGNAL);

                            if (ret < 0){
                                perror("send error");
                                throw -1;
                                break;
                            }
                            else{
                                //cout << "send: " << msg << endl;
                                CD->send_log.push_back(msg);
                                string log;
                                log = "send-"+(string)(msg);
                                msgLog[CD->ID].push_back(log);

                                string tmp = getUtcTimeStr() + " send: " + CD->ID + " " + (string)msg;
                                whole_log.push_back(tmp);
                                CD -> seq++;
                            }
                        }
                        catch(int expn){
                            cout << "send error" << endl;
                            break;
                        }
                        try{
                            memset(msg, 0x0, sizeof(msg));
                            /*
                            St_SERVER_OR_CLIENT_JSON_DATA json_data_SPAT = messageProcessor::set_JSON_DATA_SPAT();

                            uint8_t* serial_Json_DATA = (uint8_t*)messageProcessor::serialize_JSON_DATA(json_data_SPAT);
                            int serial_Json_DATA_Length = HEADER_SIZE + json_data_SPAT.header.PayloadLength;
                            */

                            St_SIMULATOR_TX_J2735_DATA data = messageProcessor::set_SIMULATOR_TX_DATA(MESSAGE_ID_VALUE_SPAT, spat_encodedMessage_sample, sizeof(spat_encodedMessage_sample));

                            data.header.Sequence = ++CD->pre_send_seq;
                            int data_size = MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG + data.payload.EncodedMessageLength;

                            uint8_t* serial_DATA = (uint8_t*)malloc(data_size);

                            memcpy(serial_DATA, &data, MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG);
                            memcpy(serial_DATA + MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG, data.payload.EncodedMessage, data.payload.EncodedMessageLength);

                            //printf("send EncodedMessage:\n");
                            //for(int i = 0; i<4; i++){
                                //printf("%02x", *(serial_DATA + MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG+i) );
                            //}
                            //printf("\n");

                            int ret = send(CD->sock, serial_DATA, data_size, MSG_NOSIGNAL);

                            if (ret < 0){
                                perror("send error");
                                throw -1;
                                break;
                            }
                            else{
                                //cout << "send: " << msg << endl;
                                CD->send_log.push_back(msg);
                                string log;
                                log = "send-"+(string)(msg);
                                msgLog[CD->ID].push_back(log);

                                string tmp = getUtcTimeStr() + " send: " + CD->ID + " " + (string)msg;
                                whole_log.push_back(tmp);
                                CD -> seq++;
                            }
                        }
                        catch(int expn){
                            cout << "send error" << endl;
                            break;
                        }
                        try{
                            memset(msg, 0x0, sizeof(msg));
                            /*
                            St_SERVER_OR_CLIENT_JSON_DATA json_data_SPAT = messageProcessor::set_JSON_DATA_SPAT();

                            uint8_t* serial_Json_DATA = (uint8_t*)messageProcessor::serialize_JSON_DATA(json_data_SPAT);
                            int serial_Json_DATA_Length = HEADER_SIZE + json_data_SPAT.header.PayloadLength;
                            */

                            St_SIMULATOR_TX_J2735_DATA data = messageProcessor::set_SIMULATOR_TX_DATA(MESSAGE_ID_VALUE_BSM, bsm_encodedMessage_sample, sizeof(bsm_encodedMessage_sample));

                            data.header.Sequence = ++CD->pre_send_seq;
                            int data_size = MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG + data.payload.EncodedMessageLength;

                            uint8_t* serial_DATA = (uint8_t*)malloc(data_size);

                            memcpy(serial_DATA, &data, MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG);
                            memcpy(serial_DATA + MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG, data.payload.EncodedMessage, data.payload.EncodedMessageLength);

                            //printf("send EncodedMessage:\n");
                            //for(int i = 0; i<4; i++){
                                //printf("%02x", *(serial_DATA + MESSAGEFRAME_SIZE_SIMULATOR_TX_WITHOUT_MSG+i) );
                            //}
                            //printf("\n");

                            int ret = send(CD->sock, serial_DATA, data_size, MSG_NOSIGNAL);

                            if (ret < 0){
                                perror("send error");
                                throw -1;
                                break;
                            }
                            else{
                                //cout << "send: " << msg << endl;
                                CD->send_log.push_back(msg);
                                string log;
                                log = "send-"+(string)(msg);
                                msgLog[CD->ID].push_back(log);

                                string tmp = getUtcTimeStr() + " send: " + CD->ID + " " + (string)msg;
                                whole_log.push_back(tmp);
                                CD -> seq++;
                            }
                        }
                        catch(int expn){
                            cout << "send error" << endl;
                            break;
                        }
                    }
                }
                else{
                    if (CD->sign){
                        uint8_t code;
                        uint16_t serviceFlag;
                        code = 0x00;
                        serviceFlag = 0x81;
                        St_SERVER_OR_SIMULATOR_SIGN_ACK ack = messageProcessor::set_ACK(code, serviceFlag);
                        uint8_t* msg = (uint8_t*)malloc(sizeof(MESSAGEFRAME_SIZE_ACK));
                        memcpy(msg, &ack, MESSAGEFRAME_SIZE_ACK);
                        int ret = send(CD->sock, msg, MESSAGEFRAME_SIZE_ACK, MSG_NOSIGNAL);
                        CD->sign_succ = true;
                        CD->pre_send_seq = 0;
                    }
                    else if(CD->denied){
                        uint8_t code;
                        uint16_t serviceFlag;
                        code = 0x01;
                        serviceFlag = 0x00;
                        St_SERVER_OR_SIMULATOR_SIGN_ACK ack = messageProcessor::set_ACK(code, serviceFlag);
                        uint8_t* msg = (uint8_t*)malloc(sizeof(MESSAGEFRAME_SIZE_ACK));
                        memcpy(msg, &ack, MESSAGEFRAME_SIZE_ACK);
                        int ret = send(CD->sock, msg, MESSAGEFRAME_SIZE_ACK, MSG_NOSIGNAL);
                        CD->sign_succ = false;
                        printf("server sign deny\n");
                        break;
                    }

                }
            //}
            //catch(int expn){

            //}
            
        }
        //printf("client %d sending stopped by something\n", CD->clnt_cnt);
    }

    void task_recv(clientData* CD){
        char msg[64];


        while(1){
            memset(CD->recv_buffer, 0, sizeof(CD->recv_buffer));
            //while(recv(CD->sock, CD->recv_buffer, 50, MSG_DONTWAIT) <= 0){
            //}
            int ret = recv(CD->sock, CD->recv_buffer, HEADER_SIZE, 0);
            //printf("%d\n", ret);
            if (ret > 0){

                uint8_t header_buf[HEADER_SIZE];
                memcpy(header_buf, CD->recv_buffer, HEADER_SIZE);
                //cout << header_buf << endl;

                St_Header header = messageProcessor::parse_header(header_buf);
                messageProcessor::print_header(header);

                uint8_t* payload_buf = (uint8_t*)malloc(sizeof(uint8_t)*header.PayloadLength);
                ret = recv(CD->sock, payload_buf, header.PayloadLength, 0);
                
                //for (int i = 0; i<header.PayloadLength; i++){
                    //printf("%02x", payload_buf[i]);
                //}
                //printf("\n");

                if(header.MessageType == MESSAGE_TYPE_SERVER_OR_SIMULATOR_SIGN){
                    St_Payload_SIGN payload_sign = messageProcessor::parse_SIGN(payload_buf);
                    messageProcessor::print_SIGN(payload_sign);

                    //clientManager::cnt++;
                    //cout << "cnt: " << clientManager::cnt << endl;
                    //if(clientManager::cnt > 3){
                    if(1){
                        CD->sign = true;
                        CD->denied = false;
                    }
                    else{
                        CD->denied = true;
                        printf("server sign unavailable\n");
                        break;
                    }
                }

                else if(header.MessageType == MESSAGE_TYPE_SERVER_OR_CLIENT_JSON_DATA){

                    St_Payload_JSON payload_json = messageProcessor::parse_json_payload(payload_buf);

                    //messageProcessor::print_json_payload(payload_json);

                    if(payload_json.MessageID == MESSAGE_ID_VALUE_BSM){
                        DATA_BSM json_bsm = messageProcessor::parse_json_bsm(payload_json.JsonMessage);
                        //messageProcessor::print_json_bsm(json_bsm);
                    }
                    else if(payload_json.MessageID == MESSAGE_ID_VALUE_PVD){
                        DATA_PVD json_pvd = messageProcessor::parse_json_pvd(payload_json.JsonMessage);
                        //messageProcessor::print_json_bsm(json_bsm);
                    }
                }

                else if(header.MessageType == MESSAGE_TYPE_SERVER_TX_J2735_DATA){
                    
                    St_Payload_SERVER_TX_J2735_DATA payload = messageProcessor::parse_SERVER_TX_payload(payload_buf);
                    messageProcessor::print_SERVER_TX_payload(payload);
                    printf("\n");

                    if(payload.MessageID == MESSAGE_ID_VALUE_BSM){
                        //DATA_BSM json_bsm = messageProcessor::parse_json_bsm(payload.EncodedMessage);
                        printf("MESSAGE_TYPE_SERVER_TX_J2735_DATA: bsm\n");
                    }
                    else if(payload.MessageID == MESSAGE_ID_VALUE_PVD){
                        //DATA_PVD json_pvd = messageProcessor::parse_json_pvd(payload.EncodedMessage);
                        printf("MESSAGE_TYPE_SERVER_TX_J2735_DATA: pvd\n");
                    }

                    MessageFrame_t* msg = NULL;

                    printf("decode again:\n\n");

                    decode_j2735_uper(&msg, (char*)payload.EncodedMessage, payload.EncodedMessageLength);
                    asn_fprint(stdout, &asn_DEF_MessageFrame, msg);

                }

            }
            else if(ret < 0){
                break;
            }
            else{
                break;
            }
        }
        cout << "recv done" << endl;
        //pthread_exit(NULL);
    }
};

class commander{
public:
    char command;
    clientManager* CM;

    void run(){
        //thread worker(&commander::work, this);
        //worker.detach();
        work();
    }

    void work(){
        char c;
        while(1){
            cout << endl << "command: (w: whole log, a: access log, r: remove client, c: exit)" << endl;
            cin >> c;
            if(c == 'w'){
                show_whole_log();
            }
            else if(c == 'a'){
                show_access_log();
            }
            else if(c == 'r'){
                string ID;
                cout << "ID: ";
                cin >> ID;
                CM->remove_client(ID);
            }
            else if(c == 'u'){
                show_user_list();
            }
            else if(c == 'c'){
                break;
            }
        }
    }

    void show_user_list(){
        for(auto CD:CM->clientMap){
            cout << CD.first << endl;
        }
    }

    void show_access_log(){
        for(auto log:CM->access_log){
            cout << log << endl;
        }
    }

    void show_whole_log(){
        for(auto log:CM->whole_log){
            cout << log << endl;
        }
    }
};

class simulator{
public:
    static int total_clnt_cnt;
    int simulator_sock;
    struct sockaddr_in addr;
    char buffer[1024];
    int len, recv_len;
    unsigned int  addr_len;
    thread server_thread;
    clientManager CM;
    commander CDR;

    struct sockaddr_in simulator_addr;
    unsigned int simulator_addr_len;

    int init(){
        if((simulator_sock = socket(AF_INET, SOCK_STREAM, 0))<0){
            perror("simulator socket ");
            return 1;
        }
        memset(&addr, 0x00, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_ANY);
        addr.sin_port = htons(9998);

        if(bind(simulator_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
            perror("bind ");
            return 1;
        }    

        if(listen(simulator_sock, MAXPENDING) < 0){
            perror("listen ");
            return 1;
        }   

        CM.simulator_sock = simulator_sock;

        CDR.CM = &CM;

        return 0;
    }

    void start(){
        CM.run();
        CDR.run();
    }
};

int main(){


    size_t siz = messageProcessor::ConvertHexStrToArray(bsm_tmp, 334, bsm_encodedMessage_sample);
    siz = messageProcessor::ConvertHexStrToArray(map_tmp, sizeof(map_encodedMessage_sample), map_encodedMessage_sample);
    siz = messageProcessor::ConvertHexStrToArray(spat_tmp, sizeof(spat_encodedMessage_sample), spat_encodedMessage_sample);


    simulator MySimulator;
    MySimulator.init();
    MySimulator.start();

    //DATA_SPAT spat = messageProcessor::set_Json_SPAT();
    //messageProcessor::print_Json_SPAT(spat);
    //messageProcessor::get_str_JSON_SPAT(spat);

    //St_SERVER_OR_CLIENT_SIGN sign = messageProcessor::set_SIGN();
    //messageProcessor::print_SIGN(sign);

    //St_SERVER_OR_CLIENT_JSON_DATA json_data_MAP = messageProcessor::set_JSON_DATA_MAP();
    //uint8_t* serial_Json_DATA = messageProcessor::serialize_JSON_DATA(json_data_MAP);
}

